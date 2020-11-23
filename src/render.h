#ifndef ATTYR_RENDER_H
#define ATTYR_RENDER_H

#include "rasterize.h"

void attyr_render_truecolor(attyr_framebuffer_t *buffer);

void attyr_render_8bit(attyr_framebuffer_t *buffer);

void attyr_render_ascii_truecolor(attyr_framebuffer_t *buffer);

void attyr_render_ascii_8bit(attyr_framebuffer_t *buffer);

#endif
