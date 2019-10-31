//
// Created by fourniem on 17/10/19.
//

#ifndef SET_H
#define SET_H

#include <stdarg.h>
#include <stdlib.h>
typedef struct set_s set_t;
typedef void (*free_set_t)(set_t* set);
typedef char (*add_item_t)(set_t *set, void* item);
typedef char (*remove_item_t)(set_t *set, void* item);
typedef char (*contains_t)(set_t *set, void* item);

struct set_s {
    void*           m_opaque;
    free_set_t      m_freeSet;
    add_item_t      m_addItem;
    remove_item_t   m_removeItem;
    contains_t      m_contains;
    int             m_capacity;
    int             m_size;
};

char new_set(set_t** o_set, ...);



#endif //SET_H
