#ifndef ATTYR_RASTERIZE_H
#define ATTYR_RASTERIZE_H

#include "matrices.h"

typedef struct {
    unsigned char r, g, b;
} attyr_color_t;

typedef struct {
    attyr_color_t *color;
    float *depth;
    unsigned int width;
    unsigned int height;
} attyr_framebuffer_t;

/*
 * Provides three vertices of a face to the rasterizer. If the vertices are in
 * clockwise order, they're considered to be forward-facing, otherwise, they're
 * considered backfacing, and dropped. If there are no faces to be rendered,
 * a vertex shader should return 0.
 *
 * vert1 - a pointer to the first output vertex
 * vert2 - a pointer to the second output vertex
 * vert3 - a pointer to the third output vertex
 * data - a pointer to some arbitrary data. When a vertex shader is called by
 *        attyr_rasterize, this is the shader_data passed to that function.
 */
typedef int (*attyr_vertex_shader_f)(attyr_vec4 *vert1,
                                     attyr_vec4 *vert2,
                                     attyr_vec4 *vert3,
                                     void *data);

/*
 * Determines the color of a particular fragment (a single cell in the color
 * buffer).
 *
 * fragment - a pointer to the output color. The xyz components are the rgb
 *            color components, and the w component is "alpha" -- if it is zero,
 *            the fragment is not rendered, otherwise, it is. The values of the
 *            components should be from 0 to 1.
 * coords - the barycentric coordinates of the current fragment. The first
 *          coordinate corresponds to vert1 in the vertex shader, the second to
 *          vert2, and the third to vert3.
 * pos - the 3D coordinates of the fragment in camera space. That is, this
 *       contains the position of the fragment after transformations have been
 *       applied, including the camera position. More often, the coordinates in
 *       world space are more useful, you'll have to interpolate them via the
 *       barycentric coordinates to find them.
 * data - a pointer to some arbitrary data, provided by the shader_data parameter
 *        in attyr_rasterize.
 */
typedef void (*attyr_fragment_shader_f)(attyr_vec4 *fragment,
                                        attyr_vec3 *coords,
                                        attyr_vec3 *pos,
                                        void *data);

/*
 * Rasterize a set of triangles to the given framebuffer. The triangles are
 * provided by the given vertex shader, which is called until it returns zero.
 * For speed, backfacing triangles are dropped, and the fragment shader is
 * called once per every fragment within the area of the face to provide color
 * data.
 *
 * buffer - a framebuffer to which to write an image
 * vert_shader - a vertex shader
 * frag_shader - a fragment shader
 * shader_data - a pointer to data, to be passed to the vertex and fragment
 *               shaders. This should generally contain some kind of state, such
 *               as the current face being rendered.
 */
void attyr_rasterize(attyr_framebuffer_t *buffer,
                     attyr_vertex_shader_f vert_shader,
                     attyr_fragment_shader_f frag_shader,
                     void *shader_data);

/*
 * Allocate and initialize a framebuffer for rendering. If the allocation fails,
 * returns null.
 */
attyr_framebuffer_t *attyr_init_framebuffer(unsigned int width, unsigned int height);

/*
 * Free the memory held by a framebuffer, including the depth and color buffers.
 */
void attyr_free_framebuffer(attyr_framebuffer_t *framebuffer);
/*
 * Clear a framebuffer in preparation for another rasterization.
 */
void attyr_reset_framebuffer(attyr_framebuffer_t *buff);

#endif
