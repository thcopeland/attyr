#include "helpers.h"
#include "common.h"
#include <stdlib.h>

void reset_render_state(render_state_t *state)
{
    state->object = 0;
    state->face = -1;
}

render_state_t *init_render_state(scene_t *scene)
{
    render_state_t *state = xmalloc(sizeof(render_state_t));
    state->scene = scene;
    state->time = 0;
    reset_render_state(state);
    return state;
}
