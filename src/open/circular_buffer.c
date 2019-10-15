#include <stdio.h>
#ifndef STDLIB_CUSTOM
	#include <stdlib.h>
#else
	#include <stdlibCustom.h>
#endif 
#include "open.h"

struct open_s {
    int m_capacity;
    void **m_items;
    int m_read_idx;
    int m_write_idx;
    char m_is_empty;
    char m_is_full;
    PrintCb_t m_printer;
};

open_t * open_create(int size, PrintCb_t printer) {
    open_t *table = malloc(sizeof(open_t));
    if (table == 0) return 0;
    table->m_items = calloc(size, sizeof(void*));
    if (table->m_items == 0) return 0;
    table->m_capacity = size;
    table->m_read_idx = 0;
    table->m_write_idx = 0;
    table->m_is_empty = 1;
    if (size > 0) {
        table->m_is_full = 0;
    }
    table->m_printer = printer;
    return table;
}

int open_add(open_t *self, void *in_data) {
    if (self->m_is_full) return OPEN_FULL;
    self->m_items[self->m_write_idx] = in_data;
    self->m_write_idx = (self->m_write_idx + 1) % self->m_capacity; 
    self->m_is_empty = 0;
    if (self->m_read_idx == self->m_write_idx) {
        self->m_is_full = 1;
    }
    return OK;
}

int open_remove(open_t *self, void **out_data) {
    if (self->m_is_empty) return OPEN_EMPTY;
    *out_data = self->m_items[self->m_read_idx];
    self->m_read_idx = (self->m_read_idx + 1) % self->m_capacity;
    self->m_is_full = 0;
    if (self->m_read_idx == self->m_write_idx) {
        self->m_is_empty = 1;
    }
    return OK;
}
int open_peek(open_t *self, void **out_data) {
    if (self->m_is_empty) return OPEN_EMPTY;
    *out_data = self->m_items[self->m_read_idx];
    return OK;
}
void open_free(open_t *self) {
    free(self->m_items);
    free(self);
}
void open_print(open_t *self) {
    printf("capacity = %d, read_idx = %d, write_idx = %d, is_empty = %d, is_full = %d\n", 
        self->m_capacity, 
        self->m_read_idx, 
        self->m_write_idx,
        self->m_is_empty,
        self->m_is_full);
    
    if (self->m_is_empty) {
        for (int i = 0; i < self->m_capacity; i++) {
            if (i!=0) {
                printf(", ");
            }
            printf("EMPTY");
        }
        printf("\n");
        return;
    }

    if (self->m_is_full) {
        for (int i = 0; i < self->m_capacity; i++) {
            if (i!=0) {
                printf(", ");
            }
            self->m_printer(self->m_items[i]);
        }
        printf("\n");
        return;
    }

    if (self->m_read_idx < self -> m_write_idx) {
        for (int i = 0; i < self->m_read_idx; i++) {
            if (i!=0) {
                printf(", ");
            }
            printf("EMPTY");
        }
        for (int i = self->m_read_idx; i < self->m_write_idx; i++) {
            if (i!=0) {
                printf(", ");
            }
            self->m_printer(self->m_items[i]);
        }
        for (int i = self->m_write_idx; i < self->m_capacity; i++) {
            if (i!=0) {
                printf(", ");
            }
            printf("EMPTY");
        }
        printf("\n");
        return;
    }

    for (int i = 0; i < self->m_write_idx; i++) {
        if (i!=0) {
            printf(", ");
        }
        self->m_printer(self->m_items[i]);
    }
    for (int i = self->m_write_idx; i < self->m_read_idx; i++) {
        if (i!=0) {
            printf(", ");
        }
        printf("EMPTY");
    }
    for (int i = self->m_read_idx; i < self->m_capacity; i++) {
        if (i!=0) {
            printf(", ");
        }
        self->m_printer(self->m_items[i]);
    }
    printf("\n");
}

char open_empty(open_t *self) {
    return self->m_is_empty;
}
char open_full(open_t *self) {
    return self->m_is_full;
}