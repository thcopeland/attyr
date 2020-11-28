#include "wavefront.h"
#include "common.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

typedef struct {
    scene_t *scene;
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
    state->object = state->face = 0;
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

int vert_shader(attyr_vec4 *v1, attyr_vec4 *v2, attyr_vec4 *v3, void *data, void **shared)
{
    render_state_t *state = data;
    scene_t *scene = state->scene;

    if (state->object < scene->objects->len) {
        object_t *object = darray_index(scene->objects, state->object);
        face_t *face = darray_index(object->faces, state->face);

        float a = state->time * 0.00525;
        mat4 combined, perspective = {
             1, 0, 0, 0,
             0, 2, 0, 0,
             0, 0, 1, 0,
             0, 0, -1, 0
         }, rotate = {
             cos(a), 0, sin(a), 0,
               0,    1,   0,    0,
             -sin(a),0, cos(a), 0,
               0,    0,   0,    1
         }, translate = {
             1, 0, 0, 0,
             0, 1, 0, -2,
             0, 0, 1, -5+a/3,
             0, 0, 0, 1
         }, transform;

         attyr_dot_mat4(&translate, &rotate, &transform);
         attyr_dot_mat4(&perspective, &transform, &combined);

         attyr_dot_mat4vec4(&combined, darray_index(scene->vertices, face->a), v1);
         attyr_dot_mat4vec4(&combined, darray_index(scene->vertices, face->b), v2);
         attyr_dot_mat4vec4(&combined, darray_index(scene->vertices, face->c), v3);

        if (++state->face >= object->faces->len) {
            state->face = 0;
            state->object++;
            state->time++;
        }

        *shared = object;

        return 1;
    }

    return 0;
}

void frag_shader(attyr_vec4 *color, attyr_vec3 *coords, attyr_vec3 *pos, void *data, void *shared)
{
    render_state_t *state = data;
    scene_t *scene = state->scene;
    object_t *object = shared;
    face_t *face = darray_index(object->faces, state->face ? state->face-1 : object->faces->len-1);
    texture_t *texture = object->texture;

    vec2 *uv1 = darray_index(scene->tex_coords, face->u),
         *uv2 = darray_index(scene->tex_coords, face->v),
         *uv3 = darray_index(scene->tex_coords, face->w);

    unsigned int u = texture->width  * (uv1->x*coords->x + uv2->x*coords->y + uv3->x*coords->z),
                 v = texture->height * (1-(uv1->y*coords->x + uv2->y*coords->y + uv3->y*coords->z));

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
        usleep(5000);
    }

    free_scene(scene);
    free_framebuffer(framebuffer);
    free(state);
}
