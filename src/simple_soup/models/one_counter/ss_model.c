#include "ss_metamodel.h"
#include "ss_model.h"

#include <stdlib.h>

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

ss_soup * ss_make_soup() {
    ss_behavior **behaviors = (ss_behavior **)malloc(2 * sizeof(ss_behavior *));
    ss_new_behavior(g0_0, a0_0, &behaviors[0]);
    ss_new_behavior(g0_1, a0_1, &behaviors[1]);

    ss_state *initial = (ss_state*) malloc(sizeof(ss_state));
    initial->counters[0] = 1;
    
    ss_soup *soup = NULL;
    ss_new_soup(initial, behaviors, 2, &soup);

    free(behaviors);
    return soup;
}

#include <stdio.h>
void print_state(ss_state *s) {
    printf("[%d]\n", s->counters[0]);
}
