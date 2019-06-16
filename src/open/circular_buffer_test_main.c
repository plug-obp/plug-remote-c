#include "open.h"
#include "buffer/buffer.h"

int main(int argc, char **argv) {

    open_t *open = open_create(5, buffer_print);

    open_print(open);

    int x = 43;
    open_add(open, buffer_create((char *)&x, sizeof(int)));
    open_print(open);
    x++;
    open_add(open, buffer_create((char *)&x, sizeof(int)));
    open_print(open);
    x++;
    open_add(open, buffer_create((char *)&x, sizeof(int)));
    open_print(open);

    buffer_t *buf;
    open_remove(open, (void **)&buf);
    open_print(open);

    x++;
    open_add(open, buffer_create((char *)&x, sizeof(int)));
    open_print(open);

    x++;
    open_add(open, buffer_create((char *)&x, sizeof(int)));
    open_print(open);

    x++;
    open_add(open, buffer_create((char *)&x, sizeof(int)));
    open_print(open);

    for (int i=0; i<5; i++) {
        open_remove(open, (void **)&buf);
        open_print(open);
    }

    open_free(open);
}