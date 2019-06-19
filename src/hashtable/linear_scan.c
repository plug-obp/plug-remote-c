#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "hashtable.h"

struct hashtable_s
{
    int m_capacity;
    int m_size;
    void** m_items;   
    hashable_callbacks_t m_callbacks;
};

hashtable_t * lht_new(int capacity, hashable_callbacks_t callbacks) {
    hashtable_t *tab = malloc(sizeof(hashtable_t));
    if (tab == 0) {
        return 0;
    }
    tab->m_capacity = capacity;
    tab->m_size = 0;
    tab->m_items = calloc(capacity, sizeof(void *));
    if (tab->m_items == 0) {
        return 0;
    }
    tab->m_callbacks = callbacks;
    return tab;
}
int lht_free(hashtable_t *table) {
    for (int i=0;i<table->m_capacity; i++) {
        if (table->m_items[i] != 0) {
            table->m_callbacks.m_free(table->m_items[i]);
        }
    }
    free(table->m_items);
    free(table);
    return 0;
}
char lht_add(hashtable_t *table, void *element) {
    uint64_t hash = table->m_callbacks.m_hash(element);
    uint64_t idx = hash % table->m_capacity;
    if (table->m_items[idx] == 0) { //empty slot found add it
        table->m_items[idx] = element;
        table->m_size++;
        return 0;
    }
    if (table->m_callbacks.m_equals(table->m_items[idx], element)) {
        //found
        return 1;
    }
    uint64_t start = idx;
    do {
        idx = (idx + 1) % table->m_capacity;
    } while (
            table->m_items[idx] != 0
        && !table->m_callbacks.m_equals(table->m_items[idx], element)
        &&  idx != start);
    
    if (idx == start) {
        return 2; // full
    }
    if (table->m_items[idx] == 0) { //empty slot found add it
        table->m_items[idx] = element;
        table->m_size++;
        return 0;
    }
    //found
    return 1;
}

int lht_size(hashtable_t *table) {
    return table->m_size;
}

void lht_print(hashtable_t *table) {
    printf("capacity = %d, size = %d\nitems={", table->m_capacity, table->m_size);
    for (int i=0; i<table->m_capacity; i++) {
        if (i!=0) {
            printf(", ");
        }
        if (table->m_items[i] == 0) {
            printf("NULL");
        } else {
            table->m_callbacks.m_print(table->m_items[i]);
        }
    }
    printf("}\n");
}
