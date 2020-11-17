#include <float.h>
#include <math.h>
#include "rasterize.h"

#define max3(a, b, c) fmax(fmax(a, b), c)
#define min3(a, b, c) fmin(fmin(a, b), c)

void rasterize(framebuffer_t *buff,
              vertex_shader_f vert_shader,
              fragment_shader_f frag_shader,
              void *shader_data)
{
    void *shared;
    vec4 v1, v2, v3, color;
    vec3 coords;

    while (vert_shader(&v1, &v2, &v3, shader_data, &shared)) {
        vec3 l1_coeff, l2_coeff, l3_coeff, w_coeff, pos;
        mat3 matrix = {
            v1.x, v2.x, v3.x,
            v1.y, v2.y, v3.y,
            v1.w, v2.w, v3.w
        };

        /* drop back-facing and very small faces */
        if (invert_mat3(&matrix) <= 0) continue;

        int min_i = to_screen_space(min3(v1.y/v1.w, v2.y/v2.w, v3.y/v3.w), buff->height, 0),
            max_i = to_screen_space(max3(v1.y/v1.w, v2.y/v2.w, v3.y/v3.w), buff->height, 1),
            min_j = to_screen_space(min3(v1.x/v1.w, v2.x/v2.w, v3.x/v3.w), buff->width, 0),
            max_j = to_screen_space(max3(v1.x/v1.w, v2.x/v2.w, v3.x/v3.w), buff->width, 1);

        init_vec3(&l1_coeff, matrix.m11, matrix.m12, matrix.m13);
        init_vec3(&l2_coeff, matrix.m21, matrix.m22, matrix.m23);
        init_vec3(&l3_coeff, matrix.m31, matrix.m32, matrix.m33);
        init_vec3(&w_coeff,  matrix.m11+matrix.m21+matrix.m31,
                             matrix.m12+matrix.m22+matrix.m32,
                             matrix.m13+matrix.m23+matrix.m33);

        for(int i = min_i; i < max_i; i++) {
            pos.y = (float) 2*i/buff->height - 1;

            for (int j = min_j; j < max_j; j++) {
                pos.x = (float) 2*j/buff->width - 1;

                float l1, l2, l3, w = 1/semi_dot(&pos, &w_coeff);

                if (w >= 0 && w < buff->depth[i * buff->width + j] &&
                    (l1=w*semi_dot(&pos, &l1_coeff)) >= 0 &&
                    (l2=w*semi_dot(&pos, &l2_coeff)) >= 0 &&
                    (l3=w*semi_dot(&pos, &l3_coeff)) >= 0) {
                    init_vec3(&coords, l1, l2, l3);
                    frag_shader(&color, &coords, w, shader_data, shared);

                    if (color.w > 0) {
                        buff->depth[i * buff->width + j] = w;
                        init_vec3(buff->color + i * buff->width + j, color.x, color.y, color.z);
                    }
                }
            }
        }
    }
}

float semi_dot(vec3 *x, vec3 *coeff)
{
    return x->x*coeff->x + x->y*coeff->y + coeff->z;
}

int to_screen_space(float z, int scale, int bias)
{
    return fmax(fmin(scale*(z+1)/2 + bias, scale), 0);
}

void reset_framebuffer(framebuffer_t *buff)
{
    for(int i = 0; i < buff->width*buff->height; i++) {
        init_vec3(buff->color+i, 0, 0, 0);
        buff->depth[i] = FLT_MAX;
    }
}
