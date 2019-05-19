#include "ss_metamodel.h"
#include <stdlib.h>

int ss_new_soup(ss_state **in_initial, int initial_count, ss_behavior **in_behaviors, int behavior_count, ss_soup **out_model) {
    ss_soup *model = (ss_soup *)malloc(sizeof(ss_soup));
    if (model == NULL) {
        return 1;
    }

    model->initial_size = initial_count;
    model->initial_states = (ss_state **)malloc(initial_count * sizeof(ss_state *));
    if (model->initial_states == NULL) {
        return 1;
    }
    for (int i = 0; i<initial_count; i++) {
        model->initial_states[i] = in_initial[i];
    }

    model->behaviors_size = behavior_count;
    model->behaviors = (ss_behavior **)malloc(behavior_count * sizeof(ss_behavior *));
    if (model->behaviors == NULL) {
        return 1;
    }
    for (int i=0; i<behavior_count; i++) {
        model->behaviors[i] = in_behaviors[i];
        model->behaviors[i]->soup = model;
    }
    *out_model = model;
    return 0;
}
void ss_free_soup(ss_soup *io_soup) {
    for (int i=0; i<io_soup->initial_size; i++) {
        free(io_soup->initial_states[i]);
    }
    free(io_soup->initial_states);
    for (int i=0; i<io_soup->behaviors_size; i++) {
        free(io_soup->behaviors[i]);
    }
    free(io_soup->behaviors);
    free(io_soup);
}

int ss_new_behavior(ss_guard_f in_guard, ss_action_f in_action, ss_behavior **out_behavior) {
    ss_behavior *behavior = (ss_behavior *)malloc(sizeof(ss_behavior));
    if (behavior == NULL) {
        return 1;
    }

    behavior->m_guard = in_guard;
    behavior->m_action = in_action;

    *out_behavior = behavior;
    return 0;
}
void ss_free_behavior(ss_behavior *io_behavior) {
    free(io_behavior);
}
