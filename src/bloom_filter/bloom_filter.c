//
// Created by fourniem on 17/10/19.
//

// #include "bloom_filter.h"
#include "set.h"
#include "hashable.h"
#include "buffer.h"
#include <stdarg.h>
#ifndef STDLIB_CUSTOM
#include <stdlib.h>
#else
#include <stdlibCustom.h>
#endif

#include "buffer.h"

// void bf_free(set_t *set);
// char bf_add(void* item, set_t *set);
// char bf_remove(void* item, set_t *set);
// char bf_contains(void* item, set_t *set);
// int bf_size(set_t *set);


struct bloom_filter_s {
    char* table;
    hashable_callbacks_t m_callbacks;

};
typedef struct bloom_filter_s bloom_filter_t;

char build_set(set_t *o_set, va_list argp){

    int i_capacity = va_arg(argp, int);
//    hashable_callbacks_t i_callbacks = va_arg(argp, hashable_callbacks_t);

    bloom_filter_t *tab = malloc(sizeof(bloom_filter_t));
    tab->table = calloc(i_capacity / 8, sizeof(char));
    tab->m_callbacks = buffer_callbacks;
    o_set->m_opaque = (void*) tab;
    // o_set->m_newSet = &bf_new;
    o_set->m_capacity = i_capacity;

    return 0;
}


void free_set(set_t *set){
    free(((bloom_filter_t*) set->m_opaque)->table);
    free(set->m_opaque);
}

char add_item(void* item, set_t *set){
    uint64_t hash = ((bloom_filter_t*) set->m_opaque)->m_callbacks.m_hash(item);
    if (((bloom_filter_t*) set->m_opaque)->table[(hash >> 3) %set->m_capacity] & (0x1 << (hash%8)) ){
        return 0;
    }
    else {
        ((bloom_filter_t*) set->m_opaque)->table[(hash >> 3) %set->m_capacity] = (((bloom_filter_t*) set->m_opaque)->table[(hash >> 3) %set->m_capacity]) | (0x1 << (hash%8));
        return 1; 
    }
}


char remove_item(void* item, set_t *set){
    return -1;
}
char contains(void* item, set_t *set){
    uint64_t hash = ((bloom_filter_t*) set->m_opaque)->m_callbacks.m_hash(item);

    return (((bloom_filter_t*) set->m_opaque)->table[(hash >> 3) %set->m_capacity] & (0x1 << (hash%8)));
}


