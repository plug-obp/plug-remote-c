

//file automatically generated from 32bit.m4
//using > m4 32bits.m4 > ss_model.c
#include "ss_metamodel.h"
#include "ss_model.h"

#ifndef STDLIB_CUSTOM
	#include <stdlib.h>
#else
	#include <stdlibCustom.h>
#endif 

#define BITS_SIZE 20
// int32_t bits[] =  {
    // 170, 377, 399, 394, 554, 
    // 1004, 208, 350, 755, 96, 
    // 305, 72, 699, 516, 675, 
    // 716, 321, 491, 777, 601
// };
//uncomment the following for a full branching factor
int32_t* TableBits = 0;

//guard action for bit 0
char gA_true_0(ss_state *source) {
    return ((source->data>>0) & 1) > 0 && ((TableBits != 0) ? ((TableBits[source->data % BITS_SIZE]>>(0) & 1) > 0) : 1);
}
int aA_true_0(ss_state *source) {
    source->data &= ~ (1 << 0);
    return 0;
}
char gA_false_0(ss_state *source) {
    return ((source->data>>0) & 1) == 0 && ((TableBits != 0) ? ((TableBits[source->data % BITS_SIZE]>>(0) & 1) > 0) : 1);
}
int aA_false_0(ss_state *source) {
    source->data |= (1 << 0);
    return 0;
}

//guard action for bit 1
char gA_true_1(ss_state *source) {
    return ((source->data>>1) & 1) > 0 && ((TableBits != 0) ? ((TableBits[source->data % BITS_SIZE]>>(1) & 1) > 0) : 1);
}
int aA_true_1(ss_state *source) {
    source->data &= ~ (1 << 1);
    return 0;
}
char gA_false_1(ss_state *source) {
    return ((source->data>>1) & 1) == 0 && ((TableBits != 0) ? ((TableBits[source->data % BITS_SIZE]>>(1) & 1) > 0) : 1);
}
int aA_false_1(ss_state *source) {
    source->data |= (1 << 1);
    return 0;
}

//guard action for bit 2
char gA_true_2(ss_state *source) {
    return ((source->data>>2) & 1) > 0 && ((TableBits != 0) ? ((TableBits[source->data % BITS_SIZE]>>(2) & 1) > 0) : 1);
}
int aA_true_2(ss_state *source) {
    source->data &= ~ (1 << 2);
    return 0;
}
char gA_false_2(ss_state *source) {
    return ((source->data>>2) & 1) == 0 && ((TableBits != 0) ? ((TableBits[source->data % BITS_SIZE]>>(2) & 1) > 0) : 1);
}
int aA_false_2(ss_state *source) {
    source->data |= (1 << 2);
    return 0;
}

//guard action for bit 3
char gA_true_3(ss_state *source) {
    return ((source->data>>3) & 1) > 0 && ((TableBits != 0) ? ((TableBits[source->data % BITS_SIZE]>>(3) & 1) > 0) : 1);
}
int aA_true_3(ss_state *source) {
    source->data &= ~ (1 << 3);
    return 0;
}
char gA_false_3(ss_state *source) {
    return ((source->data>>3) & 1) == 0 && ((TableBits != 0) ? ((TableBits[source->data % BITS_SIZE]>>(3) & 1) > 0) : 1);
}
int aA_false_3(ss_state *source) {
    source->data |= (1 << 3);
    return 0;
}



ss_soup * ss_make_soup() {
    ss_behavior **behaviors = (ss_behavior **)malloc(8 * sizeof(ss_behavior *));
    
    ss_new_behavior(gA_true_0, aA_true_0, &behaviors[0]);
    ss_new_behavior(gA_false_0, aA_false_0, &behaviors[1]);

    ss_new_behavior(gA_true_1, aA_true_1, &behaviors[2]);
    ss_new_behavior(gA_false_1, aA_false_1, &behaviors[3]);

    ss_new_behavior(gA_true_2, aA_true_2, &behaviors[4]);
    ss_new_behavior(gA_false_2, aA_false_2, &behaviors[5]);

    ss_new_behavior(gA_true_3, aA_true_3, &behaviors[6]);
    ss_new_behavior(gA_false_3, aA_false_3, &behaviors[7]);


    ss_state *initial = (ss_state*) malloc(sizeof(ss_state));
    initial->data = 0;
    
    ss_soup *soup = NULL;
    ss_new_soup(initial, behaviors, 8, &soup);

    free(behaviors);
    return soup;
}

#include <stdio.h>
void print_state(ss_state *s) {
    printf("[data=%d]\n", s->data);
}
