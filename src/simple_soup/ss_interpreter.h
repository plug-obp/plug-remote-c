#ifndef SS_INTERPRETER_H
#define SS_INTERPRETER_H

#include "ss_metamodel.h"

int ss_initial_configurations(ss_soup *in_soup, int *out_initial_count, ss_state ***out_initial);
int ss_get_fireable_transitions(ss_soup *in_soup, ss_state *in_current, char *io_fireables);
int ss_fire_transition(ss_soup *in_soup, ss_state *in_current, int behavior_id, ss_state **out_target);

#endif //SS_INTERPRETER_H