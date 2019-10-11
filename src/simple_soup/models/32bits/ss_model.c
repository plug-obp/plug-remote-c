

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

//guard action for bit 10
char gA_true_10(ss_state *source) {
    return ((source->data>>10) & 1) > 0 && ((bits != 0) ? ((bits[source->data % BITS_SIZE]>>(10) & 1) > 0) : 1);
}
int aA_true_10(ss_state *source) {
    source->data &= ~ (1 << 10);
    return 0;
}
char gA_false_10(ss_state *source) {
    return ((source->data>>10) & 1) == 0 && ((bits != 0) ? ((bits[source->data % BITS_SIZE]>>(10) & 1) > 0) : 1);
}
int aA_false_10(ss_state *source) {
    source->data |= (1 << 10);
    return 0;
}

//guard action for bit 11
char gA_true_11(ss_state *source) {
    return ((source->data>>11) & 1) > 0 && ((bits != 0) ? ((bits[source->data % BITS_SIZE]>>(11) & 1) > 0) : 1);
}
int aA_true_11(ss_state *source) {
    source->data &= ~ (1 << 11);
    return 0;
}
char gA_false_11(ss_state *source) {
    return ((source->data>>11) & 1) == 0 && ((bits != 0) ? ((bits[source->data % BITS_SIZE]>>(11) & 1) > 0) : 1);
}
int aA_false_11(ss_state *source) {
    source->data |= (1 << 11);
    return 0;
}

//guard action for bit 12
char gA_true_12(ss_state *source) {
    return ((source->data>>12) & 1) > 0 && ((bits != 0) ? ((bits[source->data % BITS_SIZE]>>(12) & 1) > 0) : 1);
}
int aA_true_12(ss_state *source) {
    source->data &= ~ (1 << 12);
    return 0;
}
char gA_false_12(ss_state *source) {
    return ((source->data>>12) & 1) == 0 && ((bits != 0) ? ((bits[source->data % BITS_SIZE]>>(12) & 1) > 0) : 1);
}
int aA_false_12(ss_state *source) {
    source->data |= (1 << 12);
    return 0;
}

//guard action for bit 13
char gA_true_13(ss_state *source) {
    return ((source->data>>13) & 1) > 0 && ((bits != 0) ? ((bits[source->data % BITS_SIZE]>>(13) & 1) > 0) : 1);
}
int aA_true_13(ss_state *source) {
    source->data &= ~ (1 << 13);
    return 0;
}
char gA_false_13(ss_state *source) {
    return ((source->data>>13) & 1) == 0 && ((bits != 0) ? ((bits[source->data % BITS_SIZE]>>(13) & 1) > 0) : 1);
}
int aA_false_13(ss_state *source) {
    source->data |= (1 << 13);
    return 0;
}

//guard action for bit 14
char gA_true_14(ss_state *source) {
    return ((source->data>>14) & 1) > 0 && ((bits != 0) ? ((bits[source->data % BITS_SIZE]>>(14) & 1) > 0) : 1);
}
int aA_true_14(ss_state *source) {
    source->data &= ~ (1 << 14);
    return 0;
}
char gA_false_14(ss_state *source) {
    return ((source->data>>14) & 1) == 0 && ((bits != 0) ? ((bits[source->data % BITS_SIZE]>>(14) & 1) > 0) : 1);
}
int aA_false_14(ss_state *source) {
    source->data |= (1 << 14);
    return 0;
}

//guard action for bit 15
char gA_true_15(ss_state *source) {
    return ((source->data>>15) & 1) > 0 && ((bits != 0) ? ((bits[source->data % BITS_SIZE]>>(15) & 1) > 0) : 1);
}
int aA_true_15(ss_state *source) {
    source->data &= ~ (1 << 15);
    return 0;
}
char gA_false_15(ss_state *source) {
    return ((source->data>>15) & 1) == 0 && ((bits != 0) ? ((bits[source->data % BITS_SIZE]>>(15) & 1) > 0) : 1);
}
int aA_false_15(ss_state *source) {
    source->data |= (1 << 15);
    return 0;
}

//guard action for bit 16
char gA_true_16(ss_state *source) {
    return ((source->data>>16) & 1) > 0 && ((bits != 0) ? ((bits[source->data % BITS_SIZE]>>(16) & 1) > 0) : 1);
}
int aA_true_16(ss_state *source) {
    source->data &= ~ (1 << 16);
    return 0;
}
char gA_false_16(ss_state *source) {
    return ((source->data>>16) & 1) == 0 && ((bits != 0) ? ((bits[source->data % BITS_SIZE]>>(16) & 1) > 0) : 1);
}
int aA_false_16(ss_state *source) {
    source->data |= (1 << 16);
    return 0;
}

//guard action for bit 17
char gA_true_17(ss_state *source) {
    return ((source->data>>17) & 1) > 0 && ((bits != 0) ? ((bits[source->data % BITS_SIZE]>>(17) & 1) > 0) : 1);
}
int aA_true_17(ss_state *source) {
    source->data &= ~ (1 << 17);
    return 0;
}
char gA_false_17(ss_state *source) {
    return ((source->data>>17) & 1) == 0 && ((bits != 0) ? ((bits[source->data % BITS_SIZE]>>(17) & 1) > 0) : 1);
}
int aA_false_17(ss_state *source) {
    source->data |= (1 << 17);
    return 0;
}

//guard action for bit 18
char gA_true_18(ss_state *source) {
    return ((source->data>>18) & 1) > 0 && ((bits != 0) ? ((bits[source->data % BITS_SIZE]>>(18) & 1) > 0) : 1);
}
int aA_true_18(ss_state *source) {
    source->data &= ~ (1 << 18);
    return 0;
}
char gA_false_18(ss_state *source) {
    return ((source->data>>18) & 1) == 0 && ((bits != 0) ? ((bits[source->data % BITS_SIZE]>>(18) & 1) > 0) : 1);
}
int aA_false_18(ss_state *source) {
    source->data |= (1 << 18);
    return 0;
}

//guard action for bit 19
char gA_true_19(ss_state *source) {
    return ((source->data>>19) & 1) > 0 && ((bits != 0) ? ((bits[source->data % BITS_SIZE]>>(19) & 1) > 0) : 1);
}
int aA_true_19(ss_state *source) {
    source->data &= ~ (1 << 19);
    return 0;
}
char gA_false_19(ss_state *source) {
    return ((source->data>>19) & 1) == 0 && ((bits != 0) ? ((bits[source->data % BITS_SIZE]>>(19) & 1) > 0) : 1);
}
int aA_false_19(ss_state *source) {
    source->data |= (1 << 19);
    return 0;
}

//guard action for bit 20
char gA_true_20(ss_state *source) {
    return ((source->data>>20) & 1) > 0 && ((bits != 0) ? ((bits[source->data % BITS_SIZE]>>(20) & 1) > 0) : 1);
}
int aA_true_20(ss_state *source) {
    source->data &= ~ (1 << 20);
    return 0;
}
char gA_false_20(ss_state *source) {
    return ((source->data>>20) & 1) == 0 && ((bits != 0) ? ((bits[source->data % BITS_SIZE]>>(20) & 1) > 0) : 1);
}
int aA_false_20(ss_state *source) {
    source->data |= (1 << 20);
    return 0;
}

//guard action for bit 21
char gA_true_21(ss_state *source) {
    return ((source->data>>21) & 1) > 0 && ((bits != 0) ? ((bits[source->data % BITS_SIZE]>>(21) & 1) > 0) : 1);
}
int aA_true_21(ss_state *source) {
    source->data &= ~ (1 << 21);
    return 0;
}
char gA_false_21(ss_state *source) {
    return ((source->data>>21) & 1) == 0 && ((bits != 0) ? ((bits[source->data % BITS_SIZE]>>(21) & 1) > 0) : 1);
}
int aA_false_21(ss_state *source) {
    source->data |= (1 << 21);
    return 0;
}

//guard action for bit 22
char gA_true_22(ss_state *source) {
    return ((source->data>>22) & 1) > 0 && ((bits != 0) ? ((bits[source->data % BITS_SIZE]>>(22) & 1) > 0) : 1);
}
int aA_true_22(ss_state *source) {
    source->data &= ~ (1 << 22);
    return 0;
}
char gA_false_22(ss_state *source) {
    return ((source->data>>22) & 1) == 0 && ((bits != 0) ? ((bits[source->data % BITS_SIZE]>>(22) & 1) > 0) : 1);
}
int aA_false_22(ss_state *source) {
    source->data |= (1 << 22);
    return 0;
}

//guard action for bit 23
char gA_true_23(ss_state *source) {
    return ((source->data>>23) & 1) > 0 && ((bits != 0) ? ((bits[source->data % BITS_SIZE]>>(23) & 1) > 0) : 1);
}
int aA_true_23(ss_state *source) {
    source->data &= ~ (1 << 23);
    return 0;
}
char gA_false_23(ss_state *source) {
    return ((source->data>>23) & 1) == 0 && ((bits != 0) ? ((bits[source->data % BITS_SIZE]>>(23) & 1) > 0) : 1);
}
int aA_false_23(ss_state *source) {
    source->data |= (1 << 23);
    return 0;
}

//guard action for bit 24
char gA_true_24(ss_state *source) {
    return ((source->data>>24) & 1) > 0 && ((bits != 0) ? ((bits[source->data % BITS_SIZE]>>(24) & 1) > 0) : 1);
}
int aA_true_24(ss_state *source) {
    source->data &= ~ (1 << 24);
    return 0;
}
char gA_false_24(ss_state *source) {
    return ((source->data>>24) & 1) == 0 && ((bits != 0) ? ((bits[source->data % BITS_SIZE]>>(24) & 1) > 0) : 1);
}
int aA_false_24(ss_state *source) {
    source->data |= (1 << 24);
    return 0;
}

//guard action for bit 25
char gA_true_25(ss_state *source) {
    return ((source->data>>25) & 1) > 0 && ((bits != 0) ? ((bits[source->data % BITS_SIZE]>>(25) & 1) > 0) : 1);
}
int aA_true_25(ss_state *source) {
    source->data &= ~ (1 << 25);
    return 0;
}
char gA_false_25(ss_state *source) {
    return ((source->data>>25) & 1) == 0 && ((bits != 0) ? ((bits[source->data % BITS_SIZE]>>(25) & 1) > 0) : 1);
}
int aA_false_25(ss_state *source) {
    source->data |= (1 << 25);
    return 0;
}

//guard action for bit 26
char gA_true_26(ss_state *source) {
    return ((source->data>>26) & 1) > 0 && ((bits != 0) ? ((bits[source->data % BITS_SIZE]>>(26) & 1) > 0) : 1);
}
int aA_true_26(ss_state *source) {
    source->data &= ~ (1 << 26);
    return 0;
}
char gA_false_26(ss_state *source) {
    return ((source->data>>26) & 1) == 0 && ((bits != 0) ? ((bits[source->data % BITS_SIZE]>>(26) & 1) > 0) : 1);
}
int aA_false_26(ss_state *source) {
    source->data |= (1 << 26);
    return 0;
}

//guard action for bit 27
char gA_true_27(ss_state *source) {
    return ((source->data>>27) & 1) > 0 && ((bits != 0) ? ((bits[source->data % BITS_SIZE]>>(27) & 1) > 0) : 1);
}
int aA_true_27(ss_state *source) {
    source->data &= ~ (1 << 27);
    return 0;
}
char gA_false_27(ss_state *source) {
    return ((source->data>>27) & 1) == 0 && ((bits != 0) ? ((bits[source->data % BITS_SIZE]>>(27) & 1) > 0) : 1);
}
int aA_false_27(ss_state *source) {
    source->data |= (1 << 27);
    return 0;
}

//guard action for bit 28
char gA_true_28(ss_state *source) {
    return ((source->data>>28) & 1) > 0 && ((bits != 0) ? ((bits[source->data % BITS_SIZE]>>(28) & 1) > 0) : 1);
}
int aA_true_28(ss_state *source) {
    source->data &= ~ (1 << 28);
    return 0;
}
char gA_false_28(ss_state *source) {
    return ((source->data>>28) & 1) == 0 && ((bits != 0) ? ((bits[source->data % BITS_SIZE]>>(28) & 1) > 0) : 1);
}
int aA_false_28(ss_state *source) {
    source->data |= (1 << 28);
    return 0;
}

//guard action for bit 29
char gA_true_29(ss_state *source) {
    return ((source->data>>29) & 1) > 0 && ((bits != 0) ? ((bits[source->data % BITS_SIZE]>>(29) & 1) > 0) : 1);
}
int aA_true_29(ss_state *source) {
    source->data &= ~ (1 << 29);
    return 0;
}
char gA_false_29(ss_state *source) {
    return ((source->data>>29) & 1) == 0 && ((bits != 0) ? ((bits[source->data % BITS_SIZE]>>(29) & 1) > 0) : 1);
}
int aA_false_29(ss_state *source) {
    source->data |= (1 << 29);
    return 0;
}

//guard action for bit 30
char gA_true_30(ss_state *source) {
    return ((source->data>>30) & 1) > 0 && ((bits != 0) ? ((bits[source->data % BITS_SIZE]>>(30) & 1) > 0) : 1);
}
int aA_true_30(ss_state *source) {
    source->data &= ~ (1 << 30);
    return 0;
}
char gA_false_30(ss_state *source) {
    return ((source->data>>30) & 1) == 0 && ((bits != 0) ? ((bits[source->data % BITS_SIZE]>>(30) & 1) > 0) : 1);
}
int aA_false_30(ss_state *source) {
    source->data |= (1 << 30);
    return 0;
}

//guard action for bit 31
char gA_true_31(ss_state *source) {
    return ((source->data>>31) & 1) > 0 && ((bits != 0) ? ((bits[source->data % BITS_SIZE]>>(31) & 1) > 0) : 1);
}
int aA_true_31(ss_state *source) {
    source->data &= ~ (1 << 31);
    return 0;
}
char gA_false_31(ss_state *source) {
    return ((source->data>>31) & 1) == 0 && ((bits != 0) ? ((bits[source->data % BITS_SIZE]>>(31) & 1) > 0) : 1);
}
int aA_false_31(ss_state *source) {
    source->data |= (1 << 31);
    return 0;
}



ss_soup * ss_make_soup() {
    ss_behavior **behaviors = (ss_behavior **)malloc(64 * sizeof(ss_behavior *));
    
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

    ss_new_behavior(gA_true_10, aA_true_10, &behaviors[20]);
    ss_new_behavior(gA_false_10, aA_false_10, &behaviors[21]);

    ss_new_behavior(gA_true_11, aA_true_11, &behaviors[22]);
    ss_new_behavior(gA_false_11, aA_false_11, &behaviors[23]);

    ss_new_behavior(gA_true_12, aA_true_12, &behaviors[24]);
    ss_new_behavior(gA_false_12, aA_false_12, &behaviors[25]);

    ss_new_behavior(gA_true_13, aA_true_13, &behaviors[26]);
    ss_new_behavior(gA_false_13, aA_false_13, &behaviors[27]);

    ss_new_behavior(gA_true_14, aA_true_14, &behaviors[28]);
    ss_new_behavior(gA_false_14, aA_false_14, &behaviors[29]);

    ss_new_behavior(gA_true_15, aA_true_15, &behaviors[30]);
    ss_new_behavior(gA_false_15, aA_false_15, &behaviors[31]);

    ss_new_behavior(gA_true_16, aA_true_16, &behaviors[32]);
    ss_new_behavior(gA_false_16, aA_false_16, &behaviors[33]);

    ss_new_behavior(gA_true_17, aA_true_17, &behaviors[34]);
    ss_new_behavior(gA_false_17, aA_false_17, &behaviors[35]);

    ss_new_behavior(gA_true_18, aA_true_18, &behaviors[36]);
    ss_new_behavior(gA_false_18, aA_false_18, &behaviors[37]);

    ss_new_behavior(gA_true_19, aA_true_19, &behaviors[38]);
    ss_new_behavior(gA_false_19, aA_false_19, &behaviors[39]);

    ss_new_behavior(gA_true_20, aA_true_20, &behaviors[40]);
    ss_new_behavior(gA_false_20, aA_false_20, &behaviors[41]);

    ss_new_behavior(gA_true_21, aA_true_21, &behaviors[42]);
    ss_new_behavior(gA_false_21, aA_false_21, &behaviors[43]);

    ss_new_behavior(gA_true_22, aA_true_22, &behaviors[44]);
    ss_new_behavior(gA_false_22, aA_false_22, &behaviors[45]);

    ss_new_behavior(gA_true_23, aA_true_23, &behaviors[46]);
    ss_new_behavior(gA_false_23, aA_false_23, &behaviors[47]);

    ss_new_behavior(gA_true_24, aA_true_24, &behaviors[48]);
    ss_new_behavior(gA_false_24, aA_false_24, &behaviors[49]);

    ss_new_behavior(gA_true_25, aA_true_25, &behaviors[50]);
    ss_new_behavior(gA_false_25, aA_false_25, &behaviors[51]);

    ss_new_behavior(gA_true_26, aA_true_26, &behaviors[52]);
    ss_new_behavior(gA_false_26, aA_false_26, &behaviors[53]);

    ss_new_behavior(gA_true_27, aA_true_27, &behaviors[54]);
    ss_new_behavior(gA_false_27, aA_false_27, &behaviors[55]);

    ss_new_behavior(gA_true_28, aA_true_28, &behaviors[56]);
    ss_new_behavior(gA_false_28, aA_false_28, &behaviors[57]);

    ss_new_behavior(gA_true_29, aA_true_29, &behaviors[58]);
    ss_new_behavior(gA_false_29, aA_false_29, &behaviors[59]);

    ss_new_behavior(gA_true_30, aA_true_30, &behaviors[60]);
    ss_new_behavior(gA_false_30, aA_false_30, &behaviors[61]);

    ss_new_behavior(gA_true_31, aA_true_31, &behaviors[62]);
    ss_new_behavior(gA_false_31, aA_false_31, &behaviors[63]);


    ss_state *initial = (ss_state*) malloc(sizeof(ss_state));
    initial->data = 0;
    
    ss_soup *soup = NULL;
    ss_new_soup(initial, behaviors, 64, &soup);

    free(behaviors);
    return soup;
}

#include <stdio.h>
void print_state(ss_state *s) {
    printf("[data=%d]\n", s->data);
}
