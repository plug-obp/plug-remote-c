#include "ss_metamodel.h"
#include "ss_model.h"

#include <stdlib.h>

#define MAX 1000

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

char gA0_0(ss_state *source){
    return source->a0 < MAX; 
}
int aA0_0(ss_state *source){
    source->a0++; 
}

char gA0_1(ss_state *source){
    return source->a0 >= MAX; 
}
int aA0_1(ss_state *source){
    source->a0 = 0; 
}

char gA1_0(ss_state *source){
    return source->a1 < MAX; 
}
int aA1_0(ss_state *source){
    source->a1++; 
}

char gA1_1(ss_state *source){
    return source->a1 >= MAX; 
}
int aA1_1(ss_state *source){
    source->a1 = 0; 
}

char gA2_0(ss_state *source){
    return source->a2 < MAX; 
}
int aA2_0(ss_state *source){
    source->a2++; 
}

char gA2_1(ss_state *source){
    return source->a2 >= MAX; 
}
int aA2_1(ss_state *source){
    source->a2 = 0; 
}

char gA3_0(ss_state *source){
    return source->a3 < MAX; 
}
int aA3_0(ss_state *source){
    source->a3++; 
}

char gA3_1(ss_state *source){
    return source->a3 >= MAX; 
}
int aA3_1(ss_state *source){
    source->a3 = 0; 
}

char gA4_0(ss_state *source){
    return source->a4 < MAX; 
}
int aA4_0(ss_state *source){
    source->a4++; 
}

char gA4_1(ss_state *source){
    return source->a4 >= MAX; 
}
int aA4_1(ss_state *source){
    source->a4 = 0; 
}

char gA5_0(ss_state *source){
    return source->a5 < MAX; 
}
int aA5_0(ss_state *source){
    source->a5++; 
}

char gA5_1(ss_state *source){
    return source->a5 >= MAX; 
}
int aA5_1(ss_state *source){
    source->a5 = 0; 
}

char gA6_0(ss_state *source){
    return source->a6 < MAX; 
}
int aA6_0(ss_state *source){
    source->a6++; 
}

char gA6_1(ss_state *source){
    return source->a6 >= MAX; 
}
int aA6_1(ss_state *source){
    source->a6 = 0; 
}

char gA7_0(ss_state *source){
    return source->a7 < MAX; 
}
int aA7_0(ss_state *source){
    source->a7++; 
}

char gA7_1(ss_state *source){
    return source->a7 >= MAX; 
}
int aA7_1(ss_state *source){
    source->a7 = 0; 
}

char gA8_0(ss_state *source){
    return source->a8 < MAX; 
}
int aA8_0(ss_state *source){
    source->a8++; 
}

char gA8_1(ss_state *source){
    return source->a8 >= MAX; 
}
int aA8_1(ss_state *source){
    source->a8 = 0; 
}

char gA9_0(ss_state *source){
    return source->a9 < MAX; 
}
int aA9_0(ss_state *source){
    source->a9++; 
}

char gA9_1(ss_state *source){
    return source->a9 >= MAX; 
}
int aA9_1(ss_state *source){
    source->a9 = 0; 
}



ss_soup * ss_make_soup() {
    ss_behavior **behaviors = (ss_behavior **)malloc(20 * sizeof(ss_behavior *));
    ss_new_behavior(gA0_0, aA_0, &behaviors[0]);
    ss_new_behavior(gA0_1, aA_1, &behaviors[1]);
    ss_new_behavior(gA1_0, aA_0, &behaviors[2]);
    ss_new_behavior(gA1_1, aA_1, &behaviors[3]);
    ss_new_behavior(gA2_0, aB_0, &behaviors[4]);
    ss_new_behavior(gA2_1, aB_1, &behaviors[5]);
    ss_new_behavior(gA3_0, aB_0, &behaviors[6]);
    ss_new_behavior(gA3_1, aB_1, &behaviors[7]);
    ss_new_behavior(gA4_0, aA_0, &behaviors[8]);
    ss_new_behavior(gA4_1, aA_1, &behaviors[9]);
    ss_new_behavior(gA5_0, aA_0, &behaviors[10]);
    ss_new_behavior(gA5_1, aA_1, &behaviors[11]);
    ss_new_behavior(gA6_0, aB_0, &behaviors[12]);
    ss_new_behavior(gA6_1, aB_1, &behaviors[13]);
    ss_new_behavior(gA7_0, aB_0, &behaviors[14]);
    ss_new_behavior(gA7_1, aB_1, &behaviors[15]);
    ss_new_behavior(gA8_0, aA_0, &behaviors[16]);
    ss_new_behavior(gA8_1, aA_1, &behaviors[17]);
    ss_new_behavior(gA9_0, aA_0, &behaviors[18]);
    ss_new_behavior(gA9_1, aA_1, &behaviors[19]);

    ss_state *initial = (ss_state*) malloc(sizeof(ss_state));
    initial->a0 = 0; 
    initial->a1 = 0; 
    initial->a2 = 0; 
    initial->a3 = 0; 
    initial->a4 = 0; 
    initial->a5 = 0; 
    initial->a6 = 0; 
    initial->a7 = 0; 
    initial->a8 = 0; 
    initial->a9 = 0; 

    ss_soup *soup = NULL;
    ss_new_soup(initial, behaviors, 20, &soup);

    free(behaviors);
    return soup;
}

#include <stdio.h>
void print_state(ss_state *s) {
    // printf("[a=%d, b=%d]\n", s->a, s->b);
}
