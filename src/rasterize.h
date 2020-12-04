#ifndef ATTYR_RASTERIZE_H
#define ATTYR_RASTERIZE_H

#include "matrices.h"

typedef struct {
    attyr_vec3 *color;
    float *depth;
    unsigned int width;
    unsigned int height;
} attyr_framebuffer_t;

typedef int (*attyr_vertex_shader_f)(attyr_vec4 *vert1,
                                     attyr_vec4 *vert2,
                                     attyr_vec4 *vert3,
                                     void *data);

typedef void (*attyr_fragment_shader_f)(attyr_vec4 *color,
                                        attyr_vec3 *coords,
                                        attyr_vec3 *pos,
                                        void *data);

void attyr_rasterize(attyr_framebuffer_t *buffer,
                     attyr_vertex_shader_f vert_shader,
                     attyr_fragment_shader_f frag_shader,
                     void *shader_data);

void attyr_reset_framebuffer(attyr_framebuffer_t *buff);

#endif
