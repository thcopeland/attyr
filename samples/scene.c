#include "utils/wavefront.h"
#include "utils/helpers.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
 * The job of a vertex shader is to fetch and perform transformations on object
 * vertices for the rasterizer.
 *
 * This vertex shader iterates over all the objects. This is not necessary, and
 * it could be more efficient to perform a separate draw call for each object.
 */
int vert_shader(attyr_vec4 *v1, attyr_vec4 *v2, attyr_vec4 *v3, void *data)
{
    /* read some initial data */
    render_state_t *state = data;
    scene_t *scene = state->scene;
    object_t *object = darray_index(scene->objects, state->object);

    /* move on to the next face. It would be more natural to do this at the end,
       but that would result in the fragment shader (which is always called
       after a vertex shader) being one face ahead. */
    if (++state->face >= object->faces->len) {
        if(++state->object >= scene->objects->len) {
            return 0; /* nothing left */
        } else {
            state->face = 0;
            object = darray_index(scene->objects, state->object);
        }
    }

    face_t *face = darray_index(object->faces, state->face);

    /* perform the transformations (in this case, a rotation, translation, and
       perspective all in one) and output the resulting vertices. */
    attyr_mult_mat4x4_vec4(&object->transform, darray_index(scene->vertices, face->a), v1);
    attyr_mult_mat4x4_vec4(&object->transform, darray_index(scene->vertices, face->b), v2);
    attyr_mult_mat4x4_vec4(&object->transform, darray_index(scene->vertices, face->c), v3);

    return 1; /* found another face */
}

/*
 * Set `output` to the color of the fragment (a pixel, roughly speaking) for the
 * current face and texture. The barycetric coordinates specify what point on
 * the face we are drawing.
 * This is used in the vertex shader.
 */
void calc_texture_fragment(vec3 *output,
                           texture_t *texture,
                           face_t *face,
                           vec3 *barycentric,
                           scene_t *scene)
{
    mat2x3 coords;
    unsigned int u, v;
    /* fetch the texture coordinates for each vertex */
    vec2 *vt1 = darray_index(scene->tex_coords, face->u),
         *vt2 = darray_index(scene->tex_coords, face->v),
         *vt3 = darray_index(scene->tex_coords, face->w),
         vt;
    /* interpolate the coordinates */
    attyr_init_mat2x3(&coords, vt1, vt2, vt3);
    attyr_mult_mat2x3_vec3(&coords, barycentric, &vt);

    /* convert to integer image space. note the 1-y correction. */
    u = texture->width*vt.x;
    v = texture->height*(1-vt.y);

    /* output the color at the coordinates */
    attyr_init_vec3(output, texture_lookup(texture, u, v, 0),
                            texture_lookup(texture, u, v, 1),
                            texture_lookup(texture, u, v, 2));
}

/*
 * Calculate the cumulative effect of each light in the scene on the brightness
 * of the point on the given face specified by the barycentric coordinates. All
 * the lights are considered point sources. Sadly, this is not very realistic.
 * This is used by the vertex shader.
 */
void calc_illumination(vec3 *output, face_t *face, vec3 *barycentric, scene_t *scene)
{
    static float ambience = 0.2;
    /* load the normals and vertex coordinates */
    vec4 *v1 = darray_index(scene->vertices, face->a),
         *v2 = darray_index(scene->vertices, face->b),
         *v3 = darray_index(scene->vertices, face->c);
    vec3 *n1 = darray_index(scene->normals, face->m),
         *n2 = darray_index(scene->normals, face->n),
         *n3 = darray_index(scene->normals, face->p),
         position, normal;

    mat3x3 verts = {
        v1->x, v2->x, v3->x,
        v1->y, v2->y, v3->y,
        v1->z, v2->z, v3->z
    }, normals = {
        n1->x, n2->x, n3->x,
        n1->y, n2->y, n3->y,
        n1->z, n2->z, n3->z
    };

    /* the illumination is initially dark everywhere */
    attyr_init_vec3(output, 0, 0, 0);

    /* interpolate the position and normals to the point specified by the
       barycentric coordinates */
    attyr_mult_mat3x3_vec3(&verts, barycentric, &position);
    attyr_mult_mat3x3_vec3(&normals, barycentric, &normal);

    for (int i = 0; i < scene->lights->len; i++) {
        light_t *light = darray_index(scene->lights, i);
        float intensity;
        vec3 dist;

        /* calculate the unit vector between the light source and point on the face
            that we're rendering */
        attyr_sub_vec3(&light->position, &position, &dist);
        attyr_normalize_vec3(&dist);

        /* calculate the projection of the light vector onto the normal vector.
           If they are parallel or near parallel, the light is "head on" and
           this will be around 1.
         */
        intensity = fmax(0, attyr_dot_vec3(&dist, &normal));

        /* account for the intensity of each color */
        output->x += light->color.x * intensity;
        output->y += light->color.y * intensity;
        output->z += light->color.z * intensity;
    }

    output->x = output->x*(1-ambience) + ambience;
    output->y = output->y*(1-ambience) + ambience;
    output->z = output->z*(1-ambience) + ambience;
}

/*
 * Given a point on a face, this fragment shader calculates the associated
 * fragments color and illumination, and outputs it. The rasterizer calls this
 * many times per face (depending on the size) to render the image.
 */
void frag_shader(vec4 *output, vec3 *coords, vec3 *pos, void *data)
{
    render_state_t *state = data;
    scene_t *scene = state->scene;
    object_t *object = darray_index(scene->objects, state->object);
    texture_t *texture = darray_index(scene->textures, object->texture);
    face_t *face = darray_index(object->faces, state->face);
    vec3 color, illum;

    /* calculate texture color */
    calc_texture_fragment(&color, texture, face, coords, scene);

    /* calculate illumination */
    calc_illumination(&illum, face, coords, scene);

    /* output the resulting color */
    attyr_init_vec4(output, fmin(1, color.x*illum.x),
                            fmin(1, color.y*illum.y),
                            fmin(1, color.z*illum.z),
                            1.0);
}

int main(int argc, char **argv)
{
    scene_t *scene = init_scene();
    load_wavefront_objects("assets/Scene.obj", scene);

    /* create a new framebuffer. Adjust the width and height as necessary for
       your terminal. */
    attyr_framebuffer_t *framebuffer = attyr_init_framebuffer(136, 70);
    render_state_t *state = init_render_state(scene);
    int wizard_tex = load_texture("assets/Wizard_Texture.raw", 1024, 1024, 3, scene),
        staff_tex = load_texture("assets/Wizard_Staff_Texture.raw", 512, 512, 3, scene),
        backdrop_tex = load_texture("assets/Backdrop_Texture.raw", 1024, 512, 3, scene),
        flower_tex = load_texture("assets/Flower_Texture.raw", 64, 64, 3, scene),
        ground_tex = load_texture("assets/Ground_Texture.raw", 1024, 1024, 3, scene),
        tree_tex = load_texture("assets/Tree_Texture.raw", 256, 256, 3, scene),
        plant_tex = load_texture("assets/Plant_Texture.raw", 32, 32, 3, scene);

    set_texture_by_name(scene, "Wizard", wizard_tex);
    set_texture_by_name(scene, "Pouch", wizard_tex);
    set_texture_by_name(scene, "Shoulder", wizard_tex);
    set_texture_by_name(scene, "Face", wizard_tex);
    set_texture_by_name(scene, "Staff", staff_tex);
    set_texture_by_name(scene, "Backdrop", backdrop_tex);
    set_texture_by_name(scene, "Flower", flower_tex);
    set_texture_by_name(scene, "Tree", tree_tex);
    set_texture_by_name(scene, "Ground", ground_tex);
    set_texture_by_name(scene, "Plant", plant_tex);

    add_light(scene, 1.5, 0.6, 0.1, 0, 0, 20);

    /* hide the cursor */
    printf("\x1b[?25l");

    for (int i = 0; i < 1000; i++) {
        for (int i = 0; i < scene->objects->len; i++) {
            /* calculate the transformations to perform on the current object */
            object_t *object = darray_index(scene->objects, i);
            float t = 5.3/(1+exp(3-state->time)); /* smooth interpolation */
            mat4 rotate, translate, perspective;
            attyr_rotate_y(t, &rotate);
            attyr_translate(&(vec3){0, -10+1.5*t, -22+3.8*t}, &translate);
            attyr_perspective(M_PI/4, 2, 0, &perspective);

             /* combine the transformations into a single matrix */
             attyr_mult_mat4x4_4x4(&translate, &rotate, &translate);
             attyr_mult_mat4x4_4x4(&perspective, &translate, &object->transform);
        }

        for (int i = 0; i < scene->lights->len; i++) {
            light_t *light = darray_index(scene->lights, i);

            if (state->time > 6) {
                attyr_scale_vec3(&light->color, 0.99);
            }
        }

        /* move the cursor to the upper left corner. This is faster than
           clearing the screen, and avoid the flickering. */
        printf("\x1b[H");

        /* render the scene to the framebuffer */
        attyr_rasterize(framebuffer, vert_shader, frag_shader, state);

        /* render the framebuffer to the terminal */
        attyr_render_truecolor(framebuffer);

        /* clear the render state */
        reset_render_state(state);

        /* clear the framebuffer */
        attyr_reset_framebuffer(framebuffer);

        state->time += 0.01;
    }

    /* show the cursor */
    printf("\x1b[?25h");

    /* clean up */
    free_scene(scene);
    attyr_free_framebuffer(framebuffer);
    free(state);
}
