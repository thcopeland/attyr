#include <attyr/attyr.h>
#include "darray.h"

/* for convenience */
typedef attyr_vec3 vec3;
typedef attyr_vec4 vec4;
typedef attyr_mat3 mat3;
typedef attyr_mat4 mat4;

/* maybe we should include this in libattyr? */
typedef struct {
    float x, y;
} vec2;

/*
 * Holds information of a single texture.
 */
typedef struct {
    char *data;
    unsigned int width, height, channels;
} texture_t;

/*
 * Holds information necessary to render a single face.
 *
 * a, b, c  - indexes of three vertices in the scene.vertice array. These should
              be in counter-clockwise order.
 * m, n, p  - indexes of three normal in the scene.normals array. Their order
              should correspond do the order of a, c, and c.
 * u, v, w  - indexes of three texture cooorinates in scene.tex_coords.
 */
typedef struct {
    unsigned int a, b, c;
    unsigned int m, n, p;
    unsigned int u, v, w;
} face_t;

/*
 * id      - a null-terminated string giving the name of the object.
 * texture - allows you to associate an object with a some texture. The texture
             should still be stored in scene.textures, but this makes fragment
             shaders easier.
 * transform - object-level (probably affine) transformation matrix.
 * faces     - an array of faces.
 */
typedef struct {
    char *id;
    texture_t *texture;
    mat4 transform;
    darray_t *faces; /* face_t */
} object_t;

/*
 * Scene information, all freed when the scene is freed. You can use these
 * however you like, or not at all, but they're designed to be:
 *
 * vertices   - an array of all vertices in the scene. These can come from
                multiple OBJ files.
 * normals    - an array of all vertex normals in the scene.
 * tex_coords - an array of the texture (UV) coordinates in the scene.
 * textures   - an array of the textures used in the scene.
 * objects    - an array of objects.
 */
typedef struct {
    darray_t *vertices; /* vec4 */
    darray_t *normals;  /* vec3 */
    darray_t *tex_coords; /* vec2 */
    darray_t *textures; /* texture_t */
    darray_t *objects;  /* object_t */
} scene_t;

/*
 * Allocate and initialize a scene with some reasonable defaults.
 */
scene_t *init_scene(void);

/*
 * Load all the OBJ objects in the given file to the given scene. If an error
 * occurs, we abort with a message to stderr.
 */
void load_wavefront_objects(char *filename, scene_t *scene);

/*
 * Load a texture from the given file.
 * width - width of the texture, in pixels
 * height - height of the texture, in pixels
 * channel_size - the number of 1-byte channels per pixel (RGB - 3, RGBA - 4).
 */
void load_texture(char *filename,
                  unsigned int width,
                  unsigned int height,
                  unsigned int channel_size,
                  scene_t *scene);

/*
 * Free the memory held by the given scene and associated data.
 */
void free_scene(scene_t *scene);
