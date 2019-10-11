

//file automatically generated from 32bit.m4
//using > m4 32bits.m4 > ss_model.c
#include "ss_metamodel.h"
#include "ss_model.h"

#include <stdlib.h>

//guard action for bit 0
char gA_true_0(ss_state *source) {
    return ((source->data>>0) & 1) > 0 && ((bits != 0) ? ((bits[source->data % BITS_SIZE]>>(0) & 1) > 0) : 1);
}
int aA_true_0(ss_state *source) {
    source->data &= ~ (1 << 0);
    return 0;
}
char gA_false_0(ss_state *source) {
    return ((source->data>>0) & 1) == 0 && ((bits != 0) ? ((bits[source->data % BITS_SIZE]>>(0) & 1) > 0) : 1);
}
int aA_false_0(ss_state *source) {
    source->data |= (1 << 0);
    return 0;
}

//guard action for bit 1
char gA_true_1(ss_state *source) {
    return ((source->data>>1) & 1) > 0 && ((bits != 0) ? ((bits[source->data % BITS_SIZE]>>(1) & 1) > 0) : 1);
}
int aA_true_1(ss_state *source) {
    source->data &= ~ (1 << 1);
    return 0;
}
char gA_false_1(ss_state *source) {
    return ((source->data>>1) & 1) == 0 && ((bits != 0) ? ((bits[source->data % BITS_SIZE]>>(1) & 1) > 0) : 1);
}
int aA_false_1(ss_state *source) {
    source->data |= (1 << 1);
    return 0;
}

//guard action for bit 2
char gA_true_2(ss_state *source) {
    return ((source->data>>2) & 1) > 0 && ((bits != 0) ? ((bits[source->data % BITS_SIZE]>>(2) & 1) > 0) : 1);
}
int aA_true_2(ss_state *source) {
    source->data &= ~ (1 << 2);
    return 0;
}
char gA_false_2(ss_state *source) {
    return ((source->data>>2) & 1) == 0 && ((bits != 0) ? ((bits[source->data % BITS_SIZE]>>(2) & 1) > 0) : 1);
}
int aA_false_2(ss_state *source) {
    source->data |= (1 << 2);
    return 0;
}

//guard action for bit 3
char gA_true_3(ss_state *source) {
    return ((source->data>>3) & 1) > 0 && ((bits != 0) ? ((bits[source->data % BITS_SIZE]>>(3) & 1) > 0) : 1);
}
int aA_true_3(ss_state *source) {
    source->data &= ~ (1 << 3);
    return 0;
}
char gA_false_3(ss_state *source) {
    return ((source->data>>3) & 1) == 0 && ((bits != 0) ? ((bits[source->data % BITS_SIZE]>>(3) & 1) > 0) : 1);
}
int aA_false_3(ss_state *source) {
    source->data |= (1 << 3);
    return 0;
}

//guard action for bit 4
char gA_true_4(ss_state *source) {
    return ((source->data>>4) & 1) > 0 && ((bits != 0) ? ((bits[source->data % BITS_SIZE]>>(4) & 1) > 0) : 1);
}
int aA_true_4(ss_state *source) {
    source->data &= ~ (1 << 4);
    return 0;
}
char gA_false_4(ss_state *source) {
    return ((source->data>>4) & 1) == 0 && ((bits != 0) ? ((bits[source->data % BITS_SIZE]>>(4) & 1) > 0) : 1);
}
int aA_false_4(ss_state *source) {
    source->data |= (1 << 4);
    return 0;
}

//guard action for bit 5
char gA_true_5(ss_state *source) {
    return ((source->data>>5) & 1) > 0 && ((bits != 0) ? ((bits[source->data % BITS_SIZE]>>(5) & 1) > 0) : 1);
}
int aA_true_5(ss_state *source) {
    source->data &= ~ (1 << 5);
    return 0;
}
char gA_false_5(ss_state *source) {
    return ((source->data>>5) & 1) == 0 && ((bits != 0) ? ((bits[source->data % BITS_SIZE]>>(5) & 1) > 0) : 1);
}
int aA_false_5(ss_state *source) {
    source->data |= (1 << 5);
    return 0;
}

//guard action for bit 6
char gA_true_6(ss_state *source) {
    return ((source->data>>6) & 1) > 0 && ((bits != 0) ? ((bits[source->data % BITS_SIZE]>>(6) & 1) > 0) : 1);
}
int aA_true_6(ss_state *source) {
    source->data &= ~ (1 << 6);
    return 0;
}
char gA_false_6(ss_state *source) {
    return ((source->data>>6) & 1) == 0 && ((bits != 0) ? ((bits[source->data % BITS_SIZE]>>(6) & 1) > 0) : 1);
}
int aA_false_6(ss_state *source) {
    source->data |= (1 << 6);
    return 0;
}

//guard action for bit 7
char gA_true_7(ss_state *source) {
    return ((source->data>>7) & 1) > 0 && ((bits != 0) ? ((bits[source->data % BITS_SIZE]>>(7) & 1) > 0) : 1);
}
int aA_true_7(ss_state *source) {
    source->data &= ~ (1 << 7);
    return 0;
}
char gA_false_7(ss_state *source) {
    return ((source->data>>7) & 1) == 0 && ((bits != 0) ? ((bits[source->data % BITS_SIZE]>>(7) & 1) > 0) : 1);
}
int aA_false_7(ss_state *source) {
    source->data |= (1 << 7);
    return 0;
}

//guard action for bit 8
char gA_true_8(ss_state *source) {
    return ((source->data>>8) & 1) > 0 && ((bits != 0) ? ((bits[source->data % BITS_SIZE]>>(8) & 1) > 0) : 1);
}
int aA_true_8(ss_state *source) {
    source->data &= ~ (1 << 8);
    return 0;
}
char gA_false_8(ss_state *source) {
    return ((source->data>>8) & 1) == 0 && ((bits != 0) ? ((bits[source->data % BITS_SIZE]>>(8) & 1) > 0) : 1);
}
int aA_false_8(ss_state *source) {
    source->data |= (1 << 8);
    return 0;
}

//guard action for bit 9
char gA_true_9(ss_state *source) {
    return ((source->data>>9) & 1) > 0 && ((bits != 0) ? ((bits[source->data % BITS_SIZE]>>(9) & 1) > 0) : 1);
}
int aA_true_9(ss_state *source) {
    source->data &= ~ (1 << 9);
    return 0;
}
char gA_false_9(ss_state *source) {
    return ((source->data>>9) & 1) == 0 && ((bits != 0) ? ((bits[source->data % BITS_SIZE]>>(9) & 1) > 0) : 1);
}
int aA_false_9(ss_state *source) {
    source->data |= (1 << 9);
    return 0;
}



ss_soup * ss_make_soup() {
    ss_behavior **behaviors = (ss_behavior **)malloc(20 * sizeof(ss_behavior *));
    
    ss_new_behavior(gA_true_0, aA_true_0, &behaviors[0]);
    ss_new_behavior(gA_false_0, aA_false_0, &behaviors[1]);

    ss_new_behavior(gA_true_1, aA_true_1, &behaviors[2]);
    ss_new_behavior(gA_false_1, aA_false_1, &behaviors[3]);

    ss_new_behavior(gA_true_2, aA_true_2, &behaviors[4]);
    ss_new_behavior(gA_false_2, aA_false_2, &behaviors[5]);

    ss_new_behavior(gA_true_3, aA_true_3, &behaviors[6]);
    ss_new_behavior(gA_false_3, aA_false_3, &behaviors[7]);

    ss_new_behavior(gA_true_4, aA_true_4, &behaviors[8]);
    ss_new_behavior(gA_false_4, aA_false_4, &behaviors[9]);

    ss_new_behavior(gA_true_5, aA_true_5, &behaviors[10]);
    ss_new_behavior(gA_false_5, aA_false_5, &behaviors[11]);

    ss_new_behavior(gA_true_6, aA_true_6, &behaviors[12]);
    ss_new_behavior(gA_false_6, aA_false_6, &behaviors[13]);

    ss_new_behavior(gA_true_7, aA_true_7, &behaviors[14]);
    ss_new_behavior(gA_false_7, aA_false_7, &behaviors[15]);

    ss_new_behavior(gA_true_8, aA_true_8, &behaviors[16]);
    ss_new_behavior(gA_false_8, aA_false_8, &behaviors[17]);

    ss_new_behavior(gA_true_9, aA_true_9, &behaviors[18]);
    ss_new_behavior(gA_false_9, aA_false_9, &behaviors[19]);


    ss_state *initial = (ss_state*) malloc(sizeof(ss_state));
    initial->data = 0;
    
    ss_soup *soup = NULL;
    ss_new_soup(initial, behaviors, 20, &soup);

    free(behaviors);
    return soup;
}

#include <stdio.h>
void print_state(ss_state *s) {
    printf("[data=%d]\n", s->data);
}
