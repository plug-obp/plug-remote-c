#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "hashable.h"

typedef struct hashtable_s hashtable_t;

hashtable_t* lht_new(int capacity, hashable_callbacks_t callbacks);
int lht_free(hashtable_t *table);
char lht_add(hashtable_t *table, void *element);
int lht_size(hashtable_t *table);
void lht_print(hashtable_t *table);




#endif