//
// Created by fourniem on 17/10/19.
//

#include "bloom_filter.h"
#include "hashable.h"
#include "buffer.h"
#include <stdarg.h>
#ifndef STDLIB_CUSTOM
#include <stdlib.h>
#else
#include <stdlibCustom.h>
#endif


struct bloom_filter_s {
    char* table;
    hashable_callbacks_t m_callbacks;
};
typedef struct bloom_filter_s bloom_filter_t;

char bf_new(int i_capacity, set_t *o_set, ...){
    va_list va;
    va_start(va, o_set);
    hashable_callbacks_t i_callbacks = va_arg(va, hashable_callbacks_t);
    va_end(va);
    o_set = malloc(sizeof(set_t));

    bloom_filter_t *tab = malloc(sizeof(bloom_filter_t));
    tab->table = calloc(i_capacity / 8, sizeof(char));
    tab->m_callbacks = i_callbacks;
    o_set->m_opaque = (void*) tab;
    return 0;
}


void bf_free(set_t *set){
    free(((bloom_filter_t*) set->m_opaque)->table);
}

char bf_add(void* item, set_t *set){
    uint64_t hash = ((bloom_filter_t*) set->m_opaque)->m_callbacks.m_hash(item);
    if (((bloom_filter_t*) set->m_opaque)->table[hash >> 3] & (0x1 << (hash%8)) ){
        return 0;
    }
    else {
        ((bloom_filter_t*) set->m_opaque)->table[hash >> 3] = (((bloom_filter_t*) set->m_opaque)->table[hash >> 3]) | (0x1 << (hash%8));
    }
}


char bf_remove(void* item, set_t *set){
    return -1;
}
char bf_contains(void* item, set_t *set){
    uint64_t hash = ((bloom_filter_t*) set->m_opaque)->m_callbacks.m_hash(item);

    return (((bloom_filter_t*) set->m_opaque)->table[hash >> 3] & (0x1 << (hash%8)));
}
int bf_size(set_t *set){
    return 0;
}


