 #include "set.h"
 
 extern void free_set(set_t* set);
 extern char add_item(void* item, set_t *set);
 extern char remove_item(void* item, set_t *set);
 extern char contains(void* item, set_t *set);
 extern char build_set(set_t *o_set, va_list argp); 

char new_set(set_t** o_set, ...){
    *o_set = malloc(sizeof(set_t));
    (*o_set)->m_addItem = &add_item;
    (*o_set)->m_removeItem = &remove_item;
    (*o_set)->m_contains = &contains;
    (*o_set)->m_freeSet = &free_set;
    (*o_set)->m_capacity = 0;
    (*o_set)->m_size = 0;
    va_list va;
    va_start(va, *o_set);
    build_set(*o_set, va);
    va_end(va);

    return 0; 
}
