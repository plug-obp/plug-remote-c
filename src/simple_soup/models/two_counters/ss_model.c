#include "ss_metamodel.h"
#include "ss_model.h"

#include <stdlib.h>

#ifndef MAX
    #define MAX 2
#endif
char gA_0(ss_state *source) {
    return source->a < MAX;
}

int aA_0(ss_state *source) {
    source->a++;
    return 0;
}

char gA_1(ss_state *source) {
    return source->a >= MAX && source->b == MAX;
}

int aA_1(ss_state *source) {
    source->a = 0;
    return 0;
}

char gB_0(ss_state *source) {
    return source->b < MAX;
}

int aB_0(ss_state *source) {
    source->b++;
    return 0;
}

char gB_1(ss_state *source) {
    return source->b >= MAX;
}

int aB_1(ss_state *source) {
    source->b = 0;
    return 0;
}

ss_soup * ss_make_soup() {
    ss_behavior **behaviors = (ss_behavior **)malloc(4 * sizeof(ss_behavior *));
    ss_new_behavior(gA_0, aA_0, &behaviors[0]);
    ss_new_behavior(gA_1, aA_1, &behaviors[1]);
    ss_new_behavior(gB_0, aB_0, &behaviors[2]);
    ss_new_behavior(gB_1, aB_1, &behaviors[3]);

    ss_state *initial = (ss_state*) malloc(sizeof(ss_state));
    initial->a = 1;
    initial->b = 0;
    
    ss_soup *soup = NULL;
    ss_new_soup(initial, behaviors, 4, &soup);

    free(behaviors);
    return soup;
}

#include <stdio.h>
void print_state(ss_state *s) {
    printf("[a=%d, b=%d]\n", s->a, s->b);
}
