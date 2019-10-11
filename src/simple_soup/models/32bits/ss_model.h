#ifndef SS_MODEL_H
#define SS_MODEL_H

#include <stdint.h>

#define SS_DYNAMIC
struct ss_state_s {
    uint32_t data;
};

#define BITS_SIZE 20
int32_t bits[] =  {
    170, 377, 399, 394, 554, 
    1004, 208, 350, 755, 96, 
    305, 72, 699, 516, 675, 
    716, 321, 491, 777, 601
};
//uncomment the following for a full branching factor
// int32_t* bits = 0;

#endif //SS_MODEL_H
