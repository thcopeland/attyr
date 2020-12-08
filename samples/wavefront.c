#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

#include "wavefront.h"
#include "common.h"

#define BUFFER_SIZE 256

static void init_object(char *buffer, unsigned int size, object_t *object);

static void init_face(char *buffer,
                      face_t *face,
                      unsigned int v_base,
                      unsigned int vn_base,
                      unsigned int vt_base);

void load_wavefront_objects(char *filename, scene_t *scene)
{
    FILE *f = fopen(filename, "r");

    if (f) {
        char buffer[BUFFER_SIZE];
        unsigned int size, line = 0;
        unsigned int v_base  = scene->vertices->len,
                     vt_base = scene->tex_coords->len,
                     vn_base = scene->normals->len;

        while((size=readline(f, buffer, BUFFER_SIZE))) {
            ++line;

            /* skip almost-empty lines and comments */
            if (size <= 1 || buffer[0] == '#' || buffer[0] == 's') continue;

            if (buffer[0] == 'v') {
                if (buffer[1] == 'n') { /* load a vertex normal */
                    vec3 normal;
                    sscanf(buffer, "vn %f %f %f", &normal.x, &normal.y, &normal.z);
                    darray_append(scene->normals, &normal);
                } else if (buffer[1] == 't') { /* load a texture coordinate */
                    vec2 coord;
                    sscanf(buffer, "vt %f %f", &coord.x, &coord.y);
                    darray_append(scene->tex_coords, &coord);
                } else if (buffer[1] == ' ') { /* load a vertex */
                    vec4 vert;
                    sscanf(buffer, "v %f %f %f", &vert.x, &vert.y, &vert.z);
                    vert.w = 1.0; /* default value */
                    darray_append(scene->vertices, &vert);
                } else {
                    die("(wavefront) Invalid keyword 'v%c' on line %d\n", buffer[1], line);
                }
            } else if (buffer[0] == 'o') { /* add a new object */
                object_t object;
                init_object(buffer, size, &object);
                darray_append(scene->objects, &object);
            } else if (buffer[0] == 'f') { /* load a face */
                if (scene->objects->len > 0) {
                    face_t face;
                    init_face(buffer, &face, v_base, vn_base, vt_base);
                    darray_append(((object_t *) darray_last(scene->objects))->faces, &face);
                } else {
                    die("(wavefront) Encountered a face on line %d before any objects\n", line);
                }
            } else {
                die("(wavefront) Encountered unrecognized keyword '%c' on line %d\n", buffer[0], line);
            }
        }

        fclose(f);
    } else {
        die("(wavefront) Unable to load %s: %s\n", filename, strerror(errno));
    }
}

texture_t *load_texture(char *filename,
                        unsigned int width,
                        unsigned int height,
                        unsigned int channel_size,
                        scene_t *scene)
{
    FILE *f = fopen(filename, "r");

    if (f) {
        texture_t texture;
        size_t r, mem = (size_t) width*height*channel_size;
        texture.data = xmalloc(mem);
        texture.width = width;
        texture.height = height;
        texture.channels = channel_size;

        if ((r=fread(texture.data, 1, mem, f)) != mem) {
            die("(texture) Unable to load texture from %s: expected %ld bytes, got %ld\n", filename, mem, r);
        }

        fclose(f);
        darray_append(scene->textures, &texture);

        return darray_last(scene->textures);
    } else {
        die("(texture) Unable to load %s: %s\n", filename, strerror(errno));
    }
}

/*
 * Initialize an object_t structure from a buffer.
 */
static void init_object(char *buffer, unsigned int size, object_t *object)
{
    object->id = xmalloc(size);
    object->faces = darray_init(sizeof(face_t), 64);
    object->texture = NULL;
    sscanf(buffer, "o %s", object->id);
}

/*
 * Initialize a face_t structure from a buffer. We adjust the vertex, texture,
 * and normal indices because they are relative to a single file.
 */
static void init_face(char *buffer,
                      face_t *face,
                      unsigned int v_base,
                      unsigned int vn_base,
                      unsigned int vt_base)
{
    sscanf(buffer, "f %i/%i/%i %i/%i/%i %i/%i/%i",
                   &face->a, &face->u, &face->m,
                   &face->b, &face->v, &face->n,
                   &face->c, &face->w, &face->p);

    face->a += v_base - 1;
    face->b += v_base - 1;
    face->c += v_base - 1;
    face->m += vn_base - 1;
    face->n += vn_base - 1;
    face->p += vn_base - 1;
    face->u += vt_base - 1;
    face->v += vt_base - 1;
    face->w += vt_base - 1;
}

scene_t *init_scene(void)
{
    scene_t *scene = xmalloc(sizeof(scene_t));

    /* some arbitrary but plausible default sizes */
    scene->vertices   = darray_init(sizeof(vec4), 512);
    scene->normals    = darray_init(sizeof(vec3), 1024);
    scene->tex_coords = darray_init(sizeof(vec2), 1024);
    scene->textures   = darray_init(sizeof(texture_t), 4);
    scene->objects    = darray_init(sizeof(object_t), 4);

    return scene;
}

void free_scene(scene_t *scene)
{
    /* free each texture's data */
    for (int i = 0; i < scene->textures->len; i++) {
        texture_t *tex = darray_index(scene->textures, i);
        free(tex->data);
    }

    /* free each object's data */
    for (int i = 0; i < scene->objects->len; i++) {
        object_t *obj = darray_index(scene->objects, i);
        darray_free(obj->faces);
        free(obj->id);
    }

    /* free flat arrays */
    darray_free(scene->vertices);
    darray_free(scene->normals);
    darray_free(scene->tex_coords);
    darray_free(scene->textures);
    darray_free(scene->objects);

    free(scene);
}
