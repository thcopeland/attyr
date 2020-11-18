#ifndef RASTERIZE_H
#define RASTERIZE_H

#include "matrices.h"

typedef struct {
    vec3 *color;
    float *depth;
    unsigned int width;
    unsigned int height;
} framebuffer_t;

typedef int (*vertex_shader_f)(vec4 *vert1,
                               vec4 *vert2,
                               vec4 *vert3,
                               void *data,
                               void **shared);

typedef void (*fragment_shader_f)(vec4 *color,
                                  vec3 *coords,
                                  vec3 *pos,
                                  void *data,
                                  void *shared);

void rasterize(framebuffer_t *buffer,
              vertex_shader_f vert_shader,
              fragment_shader_f frag_shader,
              void *shader_data);

float semi_dot(vec3 *x, vec3 *coeff);

int to_screen_space(float z, int scale, int bias);

void reset_framebuffer(framebuffer_t *buff);

#endif
