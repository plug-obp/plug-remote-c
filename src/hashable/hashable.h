#ifndef HASHABLE_H
#define HASHABLE_H

#include <stdint.h>

typedef uint64_t (*HashcodeCb_t)(void *element);
typedef int (*EqualityCb_t)(void *a, void *b);
typedef void (*FreeCb_t)(void *element);
typedef void (*PrintCb_t)(void *element);

struct hashable_callbacks_s {
    HashcodeCb_t m_hash;
    EqualityCb_t m_equals;
    FreeCb_t     m_free;
    PrintCb_t    m_print;
};
typedef struct hashable_callbacks_s hashable_callbacks_t;

#endif
