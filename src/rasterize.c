#include <float.h>
#include <math.h>
#include <stdio.h>
#include "rasterize.h"

#define max2(a, b) ((a) > (b) ? (a) : (b))
#define min2(a, b) ((a) < (b) ? (a) : (b))
#define max3(a, b, c) max2(max2(a, b), c)
#define min3(a, b, c) min2(min2(a, b), c)

void rasterize(framebuffer_t *buff,
              vertex_shader_f vert_shader,
              fragment_shader_f frag_shader,
              void *shader_data)
{
    vec3 background = { .val = { 0, 0, 0 }};

    for(int i = 0; i < buff->width*buff->height; i++) {
        dup_vec3(&background, buff->color+i);
        buff->depth[i] = FLT_MAX;
    }

    void *shared;
    vec4 v1, v2, v3;

    while (vert_shader(&v1, &v2, &v3, shader_data, &shared)) {
        v1.val[0] /= v1.val[3];
        v1.val[1] /= v1.val[3];
        v1.val[2] /= v1.val[3];

        v2.val[0] /= v2.val[3];
        v2.val[1] /= v2.val[3];
        v2.val[2] /= v2.val[3];

        v3.val[0] /= v3.val[3];
        v3.val[1] /= v3.val[3];
        v3.val[2] /= v3.val[3];

        for (unsigned int v=0; v<buff->height; v++) {
            float y = (float) 2.0*v/buff->height - 1;

            for (unsigned int u=0; u<buff->width; u++) {
                float x = (float) 2*u/buff->width - 1;

                vec2 pos = { .val = { x, y }};
                float l1 = cp_magnitude(&pos, (vec2*) &v3, (vec2*) &v2),
                      l2 = cp_magnitude(&pos, (vec2*) &v1, (vec2*) &v3),
                      l3 = cp_magnitude(&pos, (vec2*) &v2, (vec2*) &v1),
                      area = fabs(cp_magnitude((vec2*) &v1, (vec2*) &v2, (vec2*) &v3));

                if (l1 >= 0 && l2 >= 0 && l3 >= 0) {
                    l1 /= area;
                    l2 /= area;
                    l3 /= area;

                    float z = 1/(l1/v1.val[2] + l2/v2.val[2] + l3/v3.val[2]);

                    if (z < buff->depth[v*buff->width + u]) {
                        buff->depth[v*buff->width + u] = z;

                        l1 *= (z/v1.val[2]);
                        l2 *= (z/v2.val[2]);
                        l3 *= (z/v3.val[2]);

                        vec3 foreground = { .val = { z*x*x, z*y*y, z*z*z }};

                        dup_vec3(&foreground, buff->color + v*buff->width + u);
                    }
                }
            }
        }
    }
}


void init_buffers(framebuffer_t *buff)
{
    vec3 background = { .val = { 0, 0, 0 }};

    for(int i = 0; i < buff->width*buff->height; i++) {
        dup_vec3(buff->color+i, &background);
        buff->depth[i] = FLT_MAX;
    }
}

/*
 * Returns the magnitude of the cross product (lowered to two dimensions) of
 * (a-o) and (b-o).
 */
float cp_magnitude(vec2 *a, vec2 *o, vec2 *b)
{
    return (a->val[0] - o->val[0])*(b->val[1] - o->val[1]) -
           (b->val[0] - o->val[0])*(a->val[1] - o->val[1]);
}
