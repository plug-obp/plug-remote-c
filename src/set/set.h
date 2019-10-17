//
// Created by fourniem on 17/10/19.
//

#ifndef SET_H
#define SET_H

#include <stdarg.h>

typedef struct set_s set_t;

typedef char (*new_set)(int i_size, set_t* o_set, ...);
typedef void (*free_set)(set_t* set);
typedef char (*add_item)(void* item, set_t *set);
typedef char (*remove_item)(void* item, set_t *set);
typedef char (*contains)(void* item, set_t *set);



struct set_s {
    void*       m_opaque;
    new_set     m_newSet;
    free_set    m_freeSet;
    add_item    m_addItem;
    remove_item m_removeItem;
    contains    m_contains;
    int m_capacity;
    int m_size;
};

#endif //SET_H
