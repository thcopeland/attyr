#ifndef RENDER_H
#define RENDER_H

#include "rasterize.h"

void render_truecolor(framebuffer_t *buffer);

void render_8bit_color(framebuffer_t *buffer);

void render_ascii_truecolor(framebuffer_t *buff);

void render_ascii_8bit(framebuffer_t *buffer);

#endif
