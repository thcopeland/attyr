#include "utils/wavefront.h"
#include "utils/common.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    scene_t *scene;
    mat2x3 texture_coords;
    unsigned int object, face;
    float time;
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

void set_texture_by_name(scene_t *scene, char *name, int texture_index)
{
    for (int i = 0; i < scene->objects->len; i++) {
        object_t *obj = darray_index(scene->objects, i);

        if (strstr(obj->id, name)) {
            obj->texture = darray_index(scene->textures, texture_index);
        }
    }
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
    load_wavefront_objects("assets/Scene.obj", scene);

    attyr_framebuffer_t *framebuffer = init_framebuffer(136, 70);
    render_state_t *state = init_render_state(scene);
    int wizard_tex = load_texture("assets/Wizard_Texture.raw", 1024, 1024, 3, scene),
        staff_tex = load_texture("assets/Wizard_Staff_Texture.raw", 512, 512, 3, scene),
        backdrop_tex = load_texture("assets/Backdrop_Texture.raw", 1024, 512, 3, scene),
        flower_tex = load_texture("assets/Flower_Texture.raw", 64, 64, 3, scene),
        ground_tex = load_texture("assets/Ground_Texture.raw", 1024, 1024, 3, scene),
        tree_tex = load_texture("assets/Tree_Texture.raw", 256, 256, 3, scene);

    set_texture_by_name(scene, "Wizard", wizard_tex);
    set_texture_by_name(scene, "Pouch", wizard_tex);
    set_texture_by_name(scene, "Shoulder", wizard_tex);
    set_texture_by_name(scene, "Face", wizard_tex);
    set_texture_by_name(scene, "Staff", staff_tex);
    set_texture_by_name(scene, "Backdrop", backdrop_tex);
    set_texture_by_name(scene, "Flower", flower_tex);
    set_texture_by_name(scene, "Tree", tree_tex);
    set_texture_by_name(scene, "Ground", ground_tex);

    for (int i = 0; i < 630; i++) {
        for (int i = 0; i < scene->objects->len; i++) {
            object_t *object = darray_index(scene->objects, i);
            float t = 19/(1+exp(4-state->time/2));
            mat4 rotate = {
                 cos(t), 0, sin(t), 0,
                   0,    1,   0,    0,
                 -sin(t),0, cos(t), 0,
                   0,    0,   0,    1
             }, translate = {
                 1, 0, 0, 0,
                 0, 1, 0, -10+t*0.42,
                 0, 0, 1, -22+t,
                 0, 0, 0, 1
             }, perspective = {
                  1, 0, 0, 0,
                  0, 2, 0, 0,
                  0, 0, 1, 0,
                  0, 0, -1, 0
              };

             attyr_mult_mat4x4_4x4(&translate, &rotate, &translate);
             attyr_mult_mat4x4_4x4(&perspective, &translate, &object->transform);
        }

        printf("\x1b[H");
        attyr_rasterize(framebuffer, vert_shader, frag_shader, state);
        attyr_render_truecolor(framebuffer);
        reset_render_state(state);
        attyr_reset_framebuffer(framebuffer);
        state->time += 0.03;
    }

    free_scene(scene);
    free_framebuffer(framebuffer);
    free(state);
}
