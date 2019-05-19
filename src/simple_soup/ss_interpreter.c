#include "ss_interpreter.h"

#include <stdlib.h>

int ss_initial_configurations(ss_soup *in_soup, int *out_initial_count, ss_state ***out_initial) {
    *out_initial = in_soup->initial_states;
    *out_initial_count = in_soup->initial_size;
    return 1;
}
int ss_get_fireable_transitions(ss_soup *in_soup, ss_state *in_current, char *io_fireables) {
    for (int i = 0; i<in_soup->behaviors_size; i++) {
        if (in_soup->behaviors[i]->m_guard(in_current)) {
            io_fireables[i] = 1;
        } else {
            io_fireables[i] = 0;
        }
    }
    return 1;
}
int ss_fire_transition(ss_soup *in_soup, ss_state *in_current, int behavior_id, ss_state **io_target) {
    ss_state *target = (ss_state *) malloc(sizeof(ss_state));

    in_soup->behaviors[behavior_id]->m_action(in_current, target);

    *io_target = target;
    return 1;
}