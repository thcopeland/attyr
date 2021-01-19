#ifndef HELPERS_H
#define HELPERS_H

#include "wavefront.h"

typedef struct {
    scene_t *scene;
    unsigned int object, face;
    float time;
} render_state_t;

/*
 * Reset a render state so it can be reused in the next frame.
 */
void reset_render_state(render_state_t *state);

/*
 * Allocate and initialize a render state.
 */
render_state_t *init_render_state(scene_t *scene);

#endif
