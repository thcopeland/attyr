#include <attyr/attyr.h>
#include <attyr/short_names.h>
#include <unistd.h> /* usleep */
#include <stdio.h>
#include <math.h> /* cos, sin */

/*
 * These macros determine the dimensions of the framebuffer and the rendered
 * text.
 */
#define RENDER_WIDTH 120
#define RENDER_HEIGHT 60

/*
 * This structure allows us to share data between frames and between vertex
 * shader and fragment shader calls.
 */
struct renderstate {
    unsigned int face; /* The vertex of the face being rasterized */
    float time;
};

/*
 * The vertices used in the scene, stored in counter-clockwise order. The first
 * three coordinates are x, y, and z respectively. The last is the w-coordinate,
 * which should generally be 1.
 */
static vec4 vertices[] = {
    {  0.1,   0.4, 0, 1.0 },
    { -0.2,  -0.2, 0, 1.0 },
    {  0.15, -0.3, 0, 1.0 },
};

/*
 * Each triplet of numbers points to three vertices in `vertices` that define a
 * single face. In this example, the faces share the same points but one is
 * in counter-clockwise order while the other is in clockwise. This means that
 * when one is backface-culled, the other will be visible.
 */
static int faces[] = {
    0, 1, 2,
    2, 1, 0
};

/*
 * A vertex shader is called by `attyr_rasterize`. This vertex shader reads the
 * appropriate triplet of vertices from the vertex array (using the
 * `renderstate` in `data`), applies some interesting transformations, and
 * copies them to `out1`, `out2`, and `out3` to be rasterized.
 */
int vert_shader(vec4 *out1, vec4 *out2, vec4 *out3, void *data)
{
    struct renderstate *state = data;

    if (state->face >= sizeof(faces)/sizeof(faces[0])) {
        /* returning 0 indicates that all vertices have been rendered */
        return 0;
    } else {
        vec4 *in1 = vertices + faces[state->face],
             *in2 = vertices + faces[state->face + 1],
             *in3 = vertices + faces[state->face + 2];

        /* Some transformation matrices */
         mat4 rotateY = {
              cos(state->time),  0, sin(state->time), 0,
                      0,         1,         0,        0,
              -sin(state->time), 0, cos(state->time), 0,
                       0,        0,         0,        1
          }, rotateX = {
               1,          0,                   0,         0,
               0, cos(state->time/2),  sin(state->time/2), 0,
               0, -sin(state->time/2), cos(state->time/2), 0,
               0,           0,                  0,         1
           }, translate = {
            1, 0, 0, 0,
            0, 1, 0, 0,
            0, 0, 1, -0.8,
            0, 0, 0, 1
         }, perspective = {
            1, 0, 0, 0,
            0, 2, 0, 0,
            0, 0, 1, 0,
            0, 0, -1, 0
          };

          /* build a single cumulative transformation matrix */
          attyr_mult_mat4x4_4x4(&rotateX, &rotateY, &rotateX);
          attyr_mult_mat4x4_4x4(&translate, &rotateX, &translate);
          attyr_mult_mat4x4_4x4(&perspective, &translate, &perspective);

          /* multiply the matrix by an input vertex and store the result in an
             output matrix */
          attyr_mult_mat4x4_vec4(&perspective, in1, out1);
          attyr_mult_mat4x4_vec4(&perspective, in2, out2);
          attyr_mult_mat4x4_vec4(&perspective, in3, out3);

          state->face += 3;

          /* returning 1 indicates that there's a vertex to render */
          return 1;
     }
}

/*
 * Fragment shaders are also called by the rasterizer and determine the color
 * of each pixel rendered. We just use the barycentric coordinates of the pixel
 * on the face, which actually looks pretty good.
 */
void frag_shader(attyr_vec4 *color, attyr_vec3 *coords, attyr_vec3 *pos, void *data)
{
    /* The fifth parameter is a sort of transparency -- if it's zero, the pixel
     * is not written. Otherwise, it is. */
    attyr_init_vec4(color, coords->z, coords->y, coords->x, 1.0);
}

int main(int argc, char **argv)
{
    /* initialize a framebuffer */
    attyr_framebuffer_t *framebuffer = attyr_init_framebuffer(RENDER_WIDTH, RENDER_HEIGHT);

    /* initialize the render state */
    struct renderstate state = {
        .face = 0,
        .time = 0
    };

    /* hide the cursor */
    printf("\x1b[?25l");

    /* render 500 frames */
    for (int i = 0; i < 500; i++) {
        /* move the cursor to the upper left corner */
        printf("\x1b[H");

        /* clear the framebuffer */
        attyr_reset_framebuffer(framebuffer);

        /* rasterize everything to the framebuffer */
        attyr_rasterize(framebuffer, vert_shader, frag_shader, &state);

        /* output the framebuffer to the screen */
        attyr_render_truecolor(framebuffer);

        /* increment time and reset the face index */
        state.time += 0.02;
        state.face = 0;

        /* delete this if you want to see some speed! */
        usleep(5000);
    }

    /* show the cursor */
    printf("\x1b[?25h");

    /* clean up */
    attyr_free_framebuffer(framebuffer);
}
