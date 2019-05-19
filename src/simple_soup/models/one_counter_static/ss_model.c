#include "ss_metamodel.h"
#include "ss_model.h"

#include <stdlib.h>

//model definition
#define MAX 2

char g0_0(ss_state *source) {
    return source->counters[0] < MAX;
}

int a0_0(ss_state *source) {
    source->counters[0]++;
    return 0;
}

char g0_1(ss_state *source) {
    return source -> counters[0] >= MAX;
}

int a0_1(ss_state *source) {
    source->counters[0] = 0;
    return 0;
}

//static model instantiation
int counter[1] = {0};

ss_state state0 = {
    .counters = counter
};

ss_state *states[1] = { &state0 };

ss_behavior beh0 = {
    .soup = 0,
    .m_guard = g0_0,
    .m_action = a0_0,
};

ss_behavior beh1 = {
    .soup = 0,
    .m_guard = g0_1,
    .m_action = a0_1,
};

ss_behavior *behaviors[2] = {&beh0, &beh1};

ss_soup soup = {
    .initial_states = states,
    .initial_size = 1,
    .behaviors = behaviors,
    .behaviors_size = 2
};

ss_soup * ss_make_soup() {
    for (int i=0; i < soup.behaviors_size; i++) {
        soup.behaviors[i]->soup = &soup;
    }
    return &soup;
}

#include <stdio.h>
void print_state(ss_state *s) {
    printf("[%d]\n", s->counters[0]);
}
