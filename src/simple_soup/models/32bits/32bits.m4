divert(-1)
# forloop(i, from, to, stmt)

define(`forloop', `pushdef(`$1', `$2')_forloop(`$1', `$2', `$3', `$4')popdef(`$1')')
define(`_forloop',
       `$4`'ifelse($1, `$3', ,
			 `define(`$1', incr($1))_forloop(`$1', `$2', `$3', `$4')')')

define(N,2)

define(isFireable, `((TableBits != 0) ? ((TableBits[source->data % BITS_SIZE]>>($1) & 1) > 0) : 1)')  

define(guard_true, `char gA_true_$1(ss_state *source) {
    return ((source->data>>$1) & 1) > 0 && isFireable($1);
}')

define(ref_guard_true, `gA_true_$1')

define(action_true, `int aA_true_$1(ss_state *source) {
    source->data &= ~ (1 << $1);
    return 0;
}')

define(ref_action_true, `aA_true_$1')

define(guard_false, `char gA_false_$1(ss_state *source) {
    return ((source->data>>$1) & 1) == 0 && isFireable($1);
}')

define(ref_guard_false, `gA_false_$1')

define(action_false, `int aA_false_$1(ss_state *source) {
    source->data |= (1 << $1);
    return 0;
}')

define(ref_action_false, `aA_false_$1')

define(process, `//guard action for bit $1
guard_true($1)
action_true($1)
guard_false($1)
action_false($1)

')

define(add_process, `
    ss_new_behavior(ref_guard_true($1), ref_action_true($1), &behaviors[eval(2*$1)]);
    ss_new_behavior(ref_guard_false($1), ref_action_false($1), &behaviors[eval(2*$1+1)]);
')
divert

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

forloop(i,0,eval(N-1),`process(i)')

ss_soup * ss_make_soup() {
    ss_behavior **behaviors = (ss_behavior **)malloc(eval(2*N) * sizeof(ss_behavior *));
    forloop(i,0,eval(N-1),`add_process(i)')

    ss_state *initial = (ss_state*) malloc(sizeof(ss_state));
    initial->data = 0;
    
    ss_soup *soup = NULL;
    ss_new_soup(initial, behaviors, eval(2*N), &soup);

    free(behaviors);
    return soup;
}

#include <stdio.h>
void print_state(ss_state *s) {
    printf("[data=%d]\n", s->data);
}
