#include "wavefront.h"
#include "common.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

typedef struct {
    scene_t *scene;
    mat2x3 texture_coords;
    unsigned int object, face;
    unsigned long time;
} render_state_t;

attyr_framebuffer_t *init_framebuffer(unsigned int width, unsigned int height)
{
    attyr_framebuffer_t *framebuffer = xmalloc(sizeof(attyr_framebuffer_t));

    framebuffer->width = width;
    framebuffer->height = height;
    framebuffer->color = xmalloc(sizeof(framebuffer->color[0])*width*height);
    framebuffer->depth = xmalloc(sizeof(framebuffer->depth[0])*width*height);

    attyr_reset_framebuffer(framebuffer);

    return framebuffer;
}

void free_framebuffer(attyr_framebuffer_t *framebuffer)
{
    free(framebuffer->color);
    free(framebuffer->depth);
    free(framebuffer);
}

void reset_render_state(render_state_t *state)
{
    state->object = 0;
    state->face = -1;
}

render_state_t *init_render_state(scene_t *scene)
{
    render_state_t *state = xmalloc(sizeof(render_state_t));
    state->scene = scene;
    state->time = 0;
    reset_render_state(state);
    return state;
}

float texture_lookup(texture_t *texture, unsigned int u, unsigned int v, unsigned int channel)
{
    return texture->data[(v*texture->width+u)*texture->channels+channel] / 255.0;
}

int vert_shader(attyr_vec4 *v1, attyr_vec4 *v2, attyr_vec4 *v3, void *data)
{
    render_state_t *state = data;
    scene_t *scene = state->scene;
    object_t *object = darray_index(scene->objects, state->object);

    if (++state->face >= object->faces->len) {
        if(++state->object >= scene->objects->len) {
            return 0;
        } else {
            state->face = 0;
            object = darray_index(scene->objects, state->object);
        }
    }

    face_t *face = darray_index(object->faces, state->face);

    attyr_mult_mat4x4_vec4(&object->transform, darray_index(scene->vertices, face->a), v1);
    attyr_mult_mat4x4_vec4(&object->transform, darray_index(scene->vertices, face->b), v2);
    attyr_mult_mat4x4_vec4(&object->transform, darray_index(scene->vertices, face->c), v3);

    attyr_init_mat2x3(&state->texture_coords, darray_index(scene->tex_coords, face->u),
                                              darray_index(scene->tex_coords, face->v),
                                              darray_index(scene->tex_coords, face->w));

    return 1;
}

void frag_shader(attyr_vec4 *color, attyr_vec3 *coords, attyr_vec3 *pos, void *data)
{
    render_state_t *state = data;
    scene_t *scene = state->scene;
    object_t *object = darray_index(scene->objects, state->object);
    texture_t *texture = object->texture;
    vec2 uv;
    attyr_mult_mat2x3_vec3(&state->texture_coords, coords, &uv);

    unsigned int u = texture->width*uv.x, v = texture->height*(1-uv.y);

    attyr_init_vec4(color, texture_lookup(texture, u, v, 0),
                           texture_lookup(texture, u, v, 1),
                           texture_lookup(texture, u, v, 2),
                           1.0);
}

int main(int argc, char **argv)
{
    scene_t *scene = init_scene();
    attyr_framebuffer_t *framebuffer = init_framebuffer(143, 78);
    render_state_t *state = init_render_state(scene);
    load_wavefront_objects("assets/Wizard.obj", scene);
    load_texture("assets/Wizard_Texture.raw", 1024, 1024, 3, scene);
    load_texture("assets/Wizard_Staff_Texture.raw", 512, 512, 3, scene);

    for (int i = 0; i < scene->objects->len; i++) {
        object_t *obj = darray_index(scene->objects, i);
        obj->texture = darray_index(scene->textures, i == 1);
    }

    for (int i = 0; i < 400; i++) {
        printf("\x1b[H");
        attyr_rasterize(framebuffer, vert_shader, frag_shader, state);
        attyr_render_truecolor(framebuffer);
        reset_render_state(state);
        attyr_reset_framebuffer(framebuffer);
        state->time++;

        for (int i = 0; i < scene->objects->len; i++) {
            object_t *object = darray_index(scene->objects, i);
            float t = state->time * 0.063;
            mat4 rotate = {
                 cos(t), 0, sin(t), 0,
                   0,    1,   0,    0,
                 -sin(t),0, cos(t), 0,
                   0,    0,   0,    1
             }, translate = {
                 1, 0, 0, 0,
                 0, 1, 0, -2,
                 0, 0, 1, -5+t/6,
                 0, 0, 0, 1
             }, perspective = {
                  1, 0, 0, 0,
                  0, 2, 0, 0,
                  0, 0, 1, 0,
                  0, 0, -1, 0
              };

             attyr_mult_mat4x4_4x4(&translate, &rotate, &object->transform);
             attyr_mult_mat4x4_4x4(&perspective, &object->transform, &object->transform);
        }

        usleep(5000);
    }

    free_scene(scene);
    free_framebuffer(framebuffer);
    free(state);
}
