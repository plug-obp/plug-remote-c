#ifndef HASHTABLE_H
#define HASHTABLE_H

typedef struct hashtable_s hashtable;
typedef struct item_s item;

struct hashtable_s
{
    int capacity;
    int size;
    item* items;    
};

struct item_s
{
    void *data;
    item *next;
};



#endif