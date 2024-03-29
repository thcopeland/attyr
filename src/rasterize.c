#include <float.h>
#include <math.h>
#include <stdlib.h>
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
    fragment->r = r * 255;
    fragment->g = g * 255;
    fragment->b = b * 255;
}

// calculate a bounding box for the face being drawn
static int calculate_bounds(attyr_vec4 *bounds, attyr_vec4 *verts)
{
    attyr_vec4 *v1 = verts, *v2 = verts + 1, *v3 = verts + 2;

    attyr_init_vec4(bounds, 1, -1, 1, -1);

    if (v1->w <= 0 && v2->w <= 0 && v3->w <= 0) {
        // no vertices in front of camera
        return 0;
    } else if (v1->w <= 0 || v2->w <= 0 || v3->w <= 0) {
        // difficult case, some vertices in front of and some behind camera
        bounds->x = -1;
        bounds->y = 1;
        bounds->z = -1;
        bounds->w = 1;
        // refine bounds by quadrants
        if (v1->x >= 0 && v2->x >= 0 && v3->x >= 0) bounds->x = 0;
        if (v1->x <= 0 && v2->x <= 0 && v3->x <= 0) bounds->y = 0;
        if (v1->y >= 0 && v2->y >= 0 && v3->y >= 0) bounds->z = 0;
        if (v1->y <= 0 && v2->y <= 0 && v3->y <= 0) bounds->w = 0;

        return 1;
    } else {
        // general case, all vertices in front of camera
        bounds->x = min3(v1->x/v1->w, v2->x/v2->w, v3->x/v3->w);
        bounds->y = max3(v1->x/v1->w, v2->x/v2->w, v3->x/v3->w);
        bounds->z = min3(v1->y/v1->w, v2->y/v2->w, v3->y/v3->w);
        bounds->w = max3(v1->y/v1->w, v2->y/v2->w, v3->y/v3->w);

        return bounds->x <= 1 && bounds->y >= -1 && bounds->z <= 1 && bounds->w >= -1;
    }
}

void attyr_rasterize(attyr_framebuffer_t *buff,
                     attyr_vertex_shader_f vert_shader,
                     attyr_fragment_shader_f frag_shader,
                     void *shader_data)
{
    attyr_vec4 verts[3], fragment, bounds;
    attyr_vec3 coords;

    while (vert_shader(verts, verts+1, verts+2, shader_data)) {
        attyr_vec3 l1_coeff, l2_coeff, l3_coeff, w_coeff, pos;
        attyr_mat3x3 h2d_verts = {
            verts->x, (verts+1)->x, (verts+2)->x,
            verts->y, (verts+1)->y, (verts+2)->y,
            verts->w, (verts+1)->w, (verts+2)->w
        };

        if (attyr_invert_mat3x3(&h2d_verts) <= 0 ||
            !calculate_bounds(&bounds, verts)) {
            continue;
        }

        int min_j = to_screen_space(bounds.x, buff->width, 0),
            max_j = to_screen_space(bounds.y, buff->width, 1),
            min_i = to_screen_space(bounds.z, buff->height, 0),
            max_i = to_screen_space(bounds.w, buff->height, 1);

        attyr_init_vec3(&l1_coeff, h2d_verts.m11, h2d_verts.m12, h2d_verts.m13);
        attyr_init_vec3(&l2_coeff, h2d_verts.m21, h2d_verts.m22, h2d_verts.m23);
        attyr_init_vec3(&l3_coeff, h2d_verts.m31, h2d_verts.m32, h2d_verts.m33);
        attyr_init_vec3(&w_coeff,  h2d_verts.m11+h2d_verts.m21+h2d_verts.m31,
                                   h2d_verts.m12+h2d_verts.m22+h2d_verts.m32,
                                   h2d_verts.m13+h2d_verts.m23+h2d_verts.m33);

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
                    pos.z = l1*verts->z + l2*(verts+1)->z + l3*(verts+2)->z;

                    if (pos.z < 0 && pos.z > buff->depth[k]) {
                        frag_shader(&fragment, &coords, &pos, shader_data);

                        if (fragment.w > 0) {
                            buff->depth[k] = pos.z;
                            set_color(buff->color + k, fragment.x, fragment.y, fragment.z);
                        }
                    }
                }
            }
        }
    }
}

attyr_framebuffer_t *attyr_init_framebuffer(unsigned int width, unsigned int height)
{
    attyr_framebuffer_t *buff = malloc(sizeof(attyr_framebuffer_t));

    if (buff) {
        buff->width = width;
        buff->height = height;
        buff->color = malloc(sizeof(buff->color[0])*width*height);
        buff->depth = malloc(sizeof(buff->depth[0])*width*height);

        if (!buff->color || !buff->depth) {
            attyr_free_framebuffer(buff);
            return NULL;
        }

        attyr_reset_framebuffer(buff);
    }

    return buff;
}

void attyr_free_framebuffer(attyr_framebuffer_t *buff)
{
    free(buff->color);
    free(buff->depth);
    free(buff);
}

void attyr_reset_framebuffer(attyr_framebuffer_t *buff)
{
    for(int i = 0; i < buff->width*buff->height; i++) {
        set_color(buff->color+i, 0, 0, 0);
        buff->depth[i] = -FLT_MAX;
    }
}
