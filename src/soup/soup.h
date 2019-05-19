#ifndef SOUP_H
#define SOUP_H
#include <stdlib.h>
#include "hashtable/hashtable.h"

typedef struct soup_model_s soup_model;
typedef struct soup_behavior_s soup_behavior;
typedef struct soup_environment_s soup_environment;
typedef struct soup_memory_s soup_memory;
typedef struct soup_symbol_s soup_symbol;

struct soup_model_s {
    soup_environment environment;
    soup_behavior behaviors;
    soup_memory initial;
};

struct soup_behavior_s {
    soup_model soup;
    int (*m_is_enabled)(soup_environment inEnvironment);
    int (*m_action)(soup_environment ioEnvironment);
};

struct soup_environment_s {
    hashtable symbols;
    soup_memory memory;
};

struct soup_memory_s {
    size_t size;
    char * data;
};

struct soup_symbol_s {
    char *name;
    size_t *size;
};

#endif /*SOUP_H*/