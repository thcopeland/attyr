#include <float.h>
#include <math.h>
#include "rasterize.h"

#define max3(a, b, c) fmax(fmax(a, b), c)
#define min3(a, b, c) fmin(fmin(a, b), c)

static float semi_dot(attyr_vec3 *x, attyr_vec3 *coeff)
{
    return x->x*coeff->x + x->y*coeff->y + coeff->z;
}

static int to_screen_space(float z, int scale, int bias)
{
    return fmax(fmin(scale*(z+1)/2 + bias, scale), 0);
}

static void set_color(attyr_color_t *fragment, float r, float g, float b)
{
    fragment->r = 255 * r;
    fragment->g = 255 * g;
    fragment->b = 255 * b;
}

void attyr_rasterize(attyr_framebuffer_t *buff,
                     attyr_vertex_shader_f vert_shader,
                     attyr_fragment_shader_f frag_shader,
                     void *shader_data)
{
    attyr_vec4 v1, v2, v3, fragment;
    attyr_vec3 coords;

    while (vert_shader(&v1, &v2, &v3, shader_data)) {
        attyr_vec3 l1_coeff, l2_coeff, l3_coeff, w_coeff, pos, clip_pos;
        attyr_mat3x3 h_verts = {
            v1.x, v2.x, v3.x,
            v1.y, v2.y, v3.y,
            v1.w, v2.w, v3.w
        }, verts = {
            v1.x, v2.x, v3.x,
            v1.y, v2.y, v3.y,
            v1.z, v2.z, v3.z
        };

        /* drop back-facing and very small faces */
        if (attyr_invert_mat3x3(&h_verts) <= 0) continue;

        int min_i, max_i, min_j, max_j;

        if (v1.w <= 0 || v2.w <= 0 || v3.w <= 0) {
            /* TODO: See James Blinn's Corner: Calculating Screen Coverage */
            min_i = 0;
            max_i = buff->height;
            min_j = 0;
            max_j = buff->width;
        } else {
            min_i = to_screen_space(min3(v1.y/v1.w, v2.y/v2.w, v3.y/v3.w), buff->height, 0);
            max_i = to_screen_space(max3(v1.y/v1.w, v2.y/v2.w, v3.y/v3.w), buff->height, 1);
            min_j = to_screen_space(min3(v1.x/v1.w, v2.x/v2.w, v3.x/v3.w), buff->width, 0);
            max_j = to_screen_space(max3(v1.x/v1.w, v2.x/v2.w, v3.x/v3.w), buff->width, 1);
        }

        attyr_init_vec3(&l1_coeff, h_verts.m11, h_verts.m12, h_verts.m13);
        attyr_init_vec3(&l2_coeff, h_verts.m21, h_verts.m22, h_verts.m23);
        attyr_init_vec3(&l3_coeff, h_verts.m31, h_verts.m32, h_verts.m33);
        attyr_init_vec3(&w_coeff,  h_verts.m11+h_verts.m21+h_verts.m31,
                                   h_verts.m12+h_verts.m22+h_verts.m32,
                                   h_verts.m13+h_verts.m23+h_verts.m33);

        for(int i = min_i; i < max_i; i++) {
            pos.y = (float) 2*i/buff->height - 1;

            for (int j = min_j; j < max_j; j++) {
                pos.x = (float) 2*j/buff->width - 1;

                float l1, l2, l3, w = 1/semi_dot(&pos, &w_coeff);

                if ((l1=w*semi_dot(&pos, &l1_coeff)) >= 0 &&
                    (l2=w*semi_dot(&pos, &l2_coeff)) >= 0 &&
                    (l3=w*semi_dot(&pos, &l3_coeff)) >= 0) {
                    int k = i * buff->width + j;
                    attyr_init_vec3(&coords, l1, l2, l3);
                    attyr_mult_mat3x3_vec3(&verts, &coords, &clip_pos);

                    if (clip_pos.z < 0 && clip_pos.z > buff->depth[k]) {
                        frag_shader(&fragment, &coords, &clip_pos, shader_data);

                        if (fragment.w > 0) {
                            buff->depth[k] = clip_pos.z;
                            set_color(buff->color + k, fragment.x, fragment.y, fragment.z);
                        }
                    }
                }
            }
        }
    }
}

void attyr_reset_framebuffer(attyr_framebuffer_t *buff)
{
    for(int i = 0; i < buff->width*buff->height; i++) {
        set_color(buff->color+i, 0, 0, 0);
        buff->depth[i] = -FLT_MAX;
    }
}
