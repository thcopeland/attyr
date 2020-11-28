#include "render.h"
#include <stdio.h>
#include <math.h>

void attyr_render_truecolor(attyr_framebuffer_t *buff)
{
    for (int i=buff->height-2; i>=0; i-=2) {
        for (int j=0; j<buff->width; j++) {
            attyr_vec3 *a = &buff->color[(i+1)*buff->width + j],
                       *b = &buff->color[i*buff->width + j];

            unsigned char r1 = 255*a->x, g1 = 255*a->y, b1 = 255*a->z,
                          r2 = 255*b->x, g2 = 255*b->y, b2 = 255*b->z;

            printf("\x1b[48;2;%i;%i;%i;38;2;%i;%i;%im\u2584", r1,g1,b1, r2,g2,b2);
        }
        printf("\x1b[0m\n");
    }
}

static unsigned char rgb_to_8bit(float r, float g, float b)
{
    float avg = (r + b + g) / 3;

    if (fmax(fmax(fabs(r-avg), fabs(g-avg)), fabs(r-avg)) < 0.03) {
        float gray = 0.2126*r + 0.7152*g + 0.0722*b;

        return 232 + 24*gray;
    } else {
        return 16 + 36*((unsigned char) (r*5))    \
                  +  6*((unsigned char) (g*5))    \
                  +    ((unsigned char) (b*5));
    }
}

void attyr_render_8bit(attyr_framebuffer_t *buff)
{
    for (int i=buff->height-2; i>=0; i-=2) {
        for (int j=0; j<buff->width; j++) {
            attyr_vec3 *a = &buff->color[(i+1)*buff->width + j],
                       *b = &buff->color[i*buff->width + j];
            unsigned char top_color    = rgb_to_8bit(a->x, a->y, a->z),
                          bottom_color = rgb_to_8bit(b->x, b->y, b->z);

            printf("\x1b[48:5:%i;38:5:%im\u2584", top_color, bottom_color);
        }
        printf("\x1b[0m\n");
    }
}

void attyr_render_ascii_truecolor(attyr_framebuffer_t *buff)
{
    for (int i=buff->height-1; i>=0; i--) {
        for (int j=0; j<buff->width; j++) {
            attyr_vec3 *pixel = &buff->color[i*buff->width + j];

            printf("\x1b[48;2;%i;%i;%im ", (unsigned char) (255*pixel->x),
                                           (unsigned char) (255*pixel->y),
                                           (unsigned char) (255*pixel->z));
        }
        printf("\x1b[0m\n");
    }
}

void attyr_render_ascii_8bit(attyr_framebuffer_t *buff)
{
    for (int i=buff->height-1; i>=0; i--) {
        for (int j=0; j<buff->width; j++) {
            attyr_vec3 *pixel = &buff->color[i*buff->width + j];

            printf("\x1b[48:5:%im ", rgb_to_8bit(pixel->x, pixel->y, pixel->z));
        }
        printf("\x1b[0m\n");
    }
}
