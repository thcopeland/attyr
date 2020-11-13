#include <float.h>
#include <math.h>
#include "rasterize.h"

#define max2(a, b) ((a) > (b) ? (a) : (b))
#define min2(a, b) ((a) < (b) ? (a) : (b))
#define max3(a, b, c) max2(max2(a, b), c)
#define min3(a, b, c) min2(min2(a, b), c)
#define clamp(min, max, x) (((x)<(min)) ? (min) : ((x)>(max))?(max):(x))

void rasterize(framebuffer_t *buff,
              vertex_shader_f vert_shader,
              fragment_shader_f frag_shader,
              void *shader_data)
{
    void *shared;
    vec4 v1, v2, v3, pos;
    while (vert_shader(&v1, &v2, &v3, shader_data, &shared)) {
        w_normalize(&v1);
        w_normalize(&v2);
        w_normalize(&v3);

        float l1, l2, l3, area = fabs(cp_magnitude(&v1, &v2, &v3));
        int max_u = clamp(0, buff->width, (max3(v1.x, v2.x, v3.x)+1)*buff->width/2+1),
            max_v = clamp(0, buff->height,(max3(v1.y, v2.y, v3.y)+1)*buff->height/2+1),
            min_u = clamp(0, buff->width, (min3(v1.x, v2.x, v3.x)+1)*buff->width/2),
            min_z = min3(v1.z, v2.z, v3.z),
            v     = clamp(0, buff->height, (min3(v1.y, v2.y, v3.y)+1)*buff->height/2),
            u;

        if (min_z <= 1) {
            for (; v<max_v; v++) {
                for (u=min_u; u<max_u; u++) {
                    int any_drawn = 0;
                    pos.y = (float) 2*v/buff->height-1;
                    pos.x = (float) 2*u/buff->width-1;

                    if ((l1=cp_magnitude(&pos, &v3, &v2)) >= 0 &&
                        (l2=cp_magnitude(&pos, &v1, &v3)) >= 0 &&
                        (l3=cp_magnitude(&pos, &v2, &v1)) >= 0) {
                        l1 /= area;
                        l2 /= area;
                        l3 /= area;

                        pos.z = 1/(l1/v1.z + l2/v2.z + l3/v3.z);

                        if (pos.z > 0 && pos.z < buff->depth[v*buff->width + u]) {
                            any_drawn = 1;
                            buff->depth[v*buff->width + u] = pos.z;

                            l1 *= (pos.z/v1.z);
                            l2 *= (pos.z/v2.z);
                            l3 *= (pos.z/v3.z);

                            float c = pos.z;
                            vec3 foreground = {c, c, c };

                            dup_vec3(&foreground, buff->color + v*buff->width + u);
                        } else if (any_drawn) {
                            continue;
                        }
                    }
                }
            }
        }
    }
}

float cp_magnitude(vec4 *a, vec4 *o, vec4 *b)
{
    return (a->x-o->x)*(b->y-o->y) - (b->x-o->x)*(a->y-o->y);
}

void w_normalize(vec4 *v)
{
    v->x /= v->w;
    v->y /= v->w;
    v->z /= v->w;
}

void reset_framebuffer(framebuffer_t *buff)
{
    for(int i = 0; i < buff->width*buff->height; i++) {
        (buff->color+i)->x = 0;
        (buff->color+i)->y = 0;
        (buff->color+i)->z = 0;
        buff->depth[i] = FLT_MAX;
    }
}
