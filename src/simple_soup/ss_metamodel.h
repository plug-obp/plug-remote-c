#ifndef SS_METAMODEL_H
#define SS_METAMODEL_H

#include "ss_model.h"
typedef struct ss_state_s ss_state;

void print_state(ss_state *s);

typedef struct ss_behavior_s ss_behavior;

struct ss_soup_s {
    ss_state **initial_states;
    int initial_size;
    ss_behavior **behaviors;
    int behaviors_size;
};
typedef struct ss_soup_s ss_soup;

int ss_new_soup(ss_state **in_initial, int initial_count, ss_behavior **in_behaviors, int behavior_count, ss_soup **out_soup);
void ss_free_soup(ss_soup *io_soup);

typedef char (*ss_guard_f)(ss_state *source);
typedef int (*ss_action_f)(ss_state *source);

struct ss_behavior_s {
    ss_soup *soup;
    ss_guard_f m_guard;
    ss_action_f m_action;
};


int ss_new_behavior(ss_guard_f in_guard, ss_action_f in_action, ss_behavior **out_behavior);
void ss_free_behavior(ss_behavior *io_behavior);

extern ss_soup* ss_make_soup();

#endif //SS_METAMODEL_H
