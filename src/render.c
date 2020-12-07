#include "render.h"
#include <stdio.h>

#define DIST2(x, y) (((x)-(y))*((x)-(y)))

void attyr_render_truecolor(attyr_framebuffer_t *buff)
{
    for (int i=buff->height-2; i>=0; i-=2) {
        for (int j=0; j<buff->width; j++) {
            attyr_color_t *upper = &buff->color[(i+1)*buff->width + j],
                          *lower = &buff->color[i*buff->width + j];

            printf("\x1b[48;2;%i;%i;%i;38;2;%i;%i;%im\u2584", upper->r, upper->g, upper->b,
                                                              lower->r, lower->g, lower->b);
        }
        printf("\x1b[0m\n");
    }
}

static unsigned char rgb_to_8bit(attyr_color_t *c)
{
    int avg = (c->r + c->g + c->b) / 3;

    if (DIST2(c->r, avg) + DIST2(c->g, avg) + DIST2(c->b, avg) < 50) {
        unsigned char gray = 0.2126*c->r + 0.7152*c->g + 0.0722*c->b;

        return 232 + 24*gray/255;
    } else {
            return 16 + 36*(c->r/43) + 6*(c->g/43) + c->b/43;
    }
}

void attyr_render_8bit(attyr_framebuffer_t *buff)
{
    for (int i=buff->height-2; i>=0; i-=2) {
        for (int j=0; j<buff->width; j++) {
            attyr_color_t *upper = &buff->color[(i+1)*buff->width + j],
                          *lower = &buff->color[i*buff->width + j];

            printf("\x1b[48:5:%i;38:5:%im\u2584", rgb_to_8bit(upper), rgb_to_8bit(lower));
        }
        printf("\x1b[0m\n");
    }
}

void attyr_render_ascii_truecolor(attyr_framebuffer_t *buff)
{
    for (int i=buff->height-1; i>=0; i--) {
        for (int j=0; j<buff->width; j++) {
            attyr_color_t *color = &buff->color[i*buff->width + j];

            printf("\x1b[48;2;%i;%i;%im ", color->r, color->g, color->b);
        }
        printf("\x1b[0m\n");
    }
}

void attyr_render_ascii_8bit(attyr_framebuffer_t *buff)
{
    for (int i=buff->height-1; i>=0; i--) {
        for (int j=0; j<buff->width; j++) {
            printf("\x1b[48:5:%im ", rgb_to_8bit(&buff->color[i*buff->width + j]));
        }
        printf("\x1b[0m\n");
    }
}
