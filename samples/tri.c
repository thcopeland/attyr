#include <attyr/attyr.h>
#include <attyr/short_names.h>
#include <unistd.h> /* usleep */
#include <stdio.h>

#define RENDER_WIDTH 100
#define RENDER_HEIGHT 50
#define RENDER_AREA (RENDER_WIDTH*RENDER_HEIGHT)

struct renderstate {
    unsigned int face;
    float time;
};

static vec4 vertices[] = {
    { 0.5,  -0.2,  -1, 1 },
    { 0,    -0.2, -3, 1 },
    { -0.5, -0.2,  -1.5, 1 }
};

static int faces[] = {
    0, 1, 2
};

int vert_shader(vec4 *out1, vec4 *out2, vec4 *out3, void *data)
{
    struct renderstate *state = data;

    if (state->face >= 3) {
        return 0;
    } else {
        vec4 *in1 = vertices + faces[state->face],
             *in2 = vertices + faces[state->face + 1],
             *in3 = vertices + faces[state->face + 2];

        mat4 translate = {
            1, 0, 0, 0,
            0, 1, 0, 0,
            0, 0, 1, state->time,
            0, 0, 0, 1
         }, perspective = {
            1, 0, 0, 0,
            0, 2, 0, 0,
            0, 0, 1, 0,
            0, 0, -1, 0
          };

         attyr_mult_mat4x4_4x4(&perspective, &translate, &perspective);

         attyr_mult_mat4x4_vec4(&perspective, in1, out1);
         attyr_mult_mat4x4_vec4(&perspective, in2, out2);
         attyr_mult_mat4x4_vec4(&perspective, in3, out3);

         state->face += 3;

         return 1;
     }
}

void frag_shader(attyr_vec4 *color, attyr_vec3 *coords, attyr_vec3 *pos, void *data)
{
    attyr_init_vec4(color, coords->x, coords->y, coords->z, 1.0);
}

int main(int argc, char **argv)
{
    /* initialize a framebuffer */
    attyr_color_t color_buffer[RENDER_AREA];
    float depth_buffer[RENDER_AREA];
    attyr_framebuffer_t framebuffer = {
        .color = color_buffer,
        .depth = depth_buffer,
        .width = RENDER_WIDTH,
        .height = RENDER_HEIGHT
    };

    struct renderstate state = {
        .face = 0,
        .time = 0
    };

    for (int i = 0; i < 300; i++) {
        /* move the cursor to the upper left corner */
        printf("\x1b[H");

        /* clear the framebuffer */
        attyr_reset_framebuffer(&framebuffer);

        /* rasterize everything to the framebuffer */
        attyr_rasterize(&framebuffer, vert_shader, frag_shader, &state);

        /* output the framebuffer to the screen */
        attyr_render_truecolor(&framebuffer);

        state.time += 0.01;
        state.face = 0;

        usleep(5000);
    }
}
