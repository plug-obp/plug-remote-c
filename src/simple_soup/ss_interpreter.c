#include "ss_interpreter.h"

#include <stdlib.h>
#include <string.h>

int ss_get_initial_configuration(ss_runtime_state *io_rstate) {
    memcpy(io_rstate->m_state, io_rstate->m_soup->initial_state, sizeof(ss_state));
    return 0;
}
int ss_get_fireable_transitions(ss_runtime_state *io_rstate) {
    ss_soup *the_soup = io_rstate->m_soup;
    io_rstate->m_fireable_size = 0;
    for (int i = 0; i<the_soup->behaviors_size; i++) {
        if (the_soup->behaviors[i]->m_guard(io_rstate->m_state)) {
            io_rstate->m_fireable_set[io_rstate->m_fireable_size++] = i;
        }
    }
    return 0;
}
int ss_fire_transition(ss_runtime_state *io_rstate, int behavior_id) {
    io_rstate->m_soup->behaviors[behavior_id]->m_action(io_rstate->m_state);
    return 0;
}