#ifndef SS_INTERPRETER_H
#define SS_INTERPRETER_H

#include "ss_metamodel.h"

int ss_get_initial_configuration(ss_runtime_state *in_rstate);
int ss_get_fireable_transitions(ss_runtime_state *in_rstate);
int ss_fire_transition(ss_runtime_state *in_rstate, int behavior_id);

#endif //SS_INTERPRETER_H