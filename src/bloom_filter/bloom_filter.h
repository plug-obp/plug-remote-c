//
// Created by fourniem on 17/10/19.
//

#ifndef PLUG_REMOTE_C_BLOOM_FILTER_H
#define PLUG_REMOTE_C_BLOOM_FILTER_H

#include <stddef.h>
#include "set.h"


extern char bf_new(int i_capacity, set_t *o_set, ...);
extern void bf_free(set_t *set);
extern char bf_add(void* item, set_t *set);
extern char bf_remove(void* item, set_t *set);
extern char bf_contains(void* item, set_t *set);
extern int bf_size(set_t *set);


set_t bf_set = {
        .m_opaque = NULL,
        .m_newSet = &bf_new,
        .m_addItem = &bf_add,
        .m_removeItem = &bf_remove,
        .m_contains = &bf_contains,
        .m_freeSet = &bf_free,
        .m_capacity = 0,
        .m_size = 0
};



#endif //PLUG_REMOTE_C_BLOOM_FILTER_H
