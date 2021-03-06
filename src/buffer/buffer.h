#ifndef BUFFER
#define BUFFER

#include <stdint.h>
#include "hashable.h"

struct buffer_s {
    char *data;
    int size;
};
typedef struct buffer_s buffer_t;

buffer_t * buffer_create(char *in_data, int size);
uint64_t buffer_hashcode(void *element);
int buffer_equals(void *a, void *b);
void buffer_free(void *element);
void buffer_print(void *element);

extern hashable_callbacks_t buffer_callbacks;

#endif
