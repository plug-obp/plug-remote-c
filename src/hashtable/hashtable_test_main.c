//#ifdef HASH_TEST
#include <stdio.h>
#include "hashtable.h"
#include "buffer/buffer.h"


int main(int argc, char**argv) {

    hashtable_t *table = lht_new(10, buffer_callbacks);

    lht_print(table);
    int e = 43;
    lht_add(table, buffer_create((char *)&e, sizeof(int)));
    lht_print(table);
    e++;
    lht_add(table, buffer_create((char *)&e, sizeof(int)));
    lht_print(table);
    e++;
    lht_add(table, buffer_create((char *)&e, sizeof(int)));
    lht_print(table);
    e++;
    lht_add(table, buffer_create((char *)&e, sizeof(int)));
    lht_print(table);

    lht_add(table, buffer_create((char *)&e, sizeof(int)));
    lht_print(table);

    double x = 3.1415;
    lht_add(table, buffer_create((char *)&x, sizeof(double)));
    lht_print(table);

    lht_free(table);
}
//#endif