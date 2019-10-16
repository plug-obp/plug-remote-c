#ifndef STDLIB_CUSTOM
#include <stdlib.h>
#else
#include <stdlibCustom.h>
#endif 
#include <string.h>
#include "buffer.h"
#include "stdio.h"
hashable_callbacks_t buffer_callbacks = {
    .m_hash = buffer_hashcode,
    .m_equals = buffer_equals,
    .m_free = buffer_free,
    .m_print = buffer_print
};

buffer_t * buffer_create(char *in_data, int size) {
    buffer_t *buf = malloc(sizeof(buffer_t));
    if (buf == 0) return 0;
    buf->data = malloc(size * sizeof(char));
    if (buf->data == 0) return 0;
    memcpy(buf->data, in_data, size);
    buf->size = size;
    return buf;
}

int buffer_equals(void *a, void *b) {
    buffer_t *theA = (buffer_t *)a;
    buffer_t *theB = (buffer_t *)b;
    if (theA->size != theB->size) {
        return 0;
    }
    return memcmp(theA->data, theB->data, theA->size) == 0;
}

void buffer_free(void *element) {
    buffer_t *buffer = (buffer_t *)element;
    free(buffer->data);
    free(buffer);
}

void buffer_print(void *element) {
    buffer_t *buffer = (buffer_t *)element;
    printf("{data: ");
    //fwrite(buffer->data, sizeof(char), buffer->size, stdout);
    for (int i = 0; i<buffer->size; i++) {
        printf("%#x ", buffer->data[i]);
    }
    printf(", size: %d}", buffer->size);
}


#ifndef MURMUR3
#include "fasthash.h"

uint64_t buffer_hashcode(void *element) {
    buffer_t *buffer = (buffer_t *) element;
    return fasthash64(buffer->data, buffer->size, 12345);
}

#else
#include "murmur3.h"
#define uint8 char

uint64_t buffer_hashcode(void* element) {
    buffer_t *buffer = (buffer_t*) element;

    return (uint64_t) murmur3_32((uint8*) buffer->data, buffer->size, 42); // Seed : Same as .vhd
}


#endif