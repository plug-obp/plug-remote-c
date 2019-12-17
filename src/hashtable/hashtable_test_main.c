//#ifdef HASH_TEST
#include <stdio.h>
#include "hashtable.h"
#include "buffer.h"
#include <assert.h>

int main(int argc, char **argv) {

    hashtable_t *table = lht_new(16, buffer_callbacks);

    lht_print(table);
//    int e = 43;
//    assert(lht_add(table, buffer_create((char *)&e, sizeof(int))) == 0);
//    lht_print(table);
//
//    e++;
//    lht_add(table, buffer_create((char *)&e, sizeof(int)));
//    lht_print(table);
//    e++;
//    lht_add(table, buffer_create((char *)&e, sizeof(int)));
//    lht_print(table);
//    e++;
//    lht_add(table, buffer_create((char *)&e, sizeof(int)));
//    lht_print(table);
//
//    lht_add(table, buffer_create((char *)&e, sizeof(int)));
//    lht_print(table);
//
//    double x = 3.1415;
//    lht_add(table, buffer_create((char *)&x, sizeof(double)));
//    lht_print(table);


    {
        int x = 42;
        assert(lht_add(table, buffer_create((char *) &x, sizeof(int))) == 0);
        lht_print(table);
    }
    {
        int x = 43;
        assert(lht_add(table, buffer_create((char *) &x, sizeof(int))) == 0);
        lht_print(table);
    }
    {
        int x = 44;
        assert(lht_add(table, buffer_create((char *) &x, sizeof(int))) == 0);
        lht_print(table);
    }
    {
        int x = 45;
        assert(lht_add(table, buffer_create((char *) &x, sizeof(int))) == 0);
        lht_print(table);
    }
    {
        int x = 46;
        assert(lht_add(table, buffer_create((char *) &x, sizeof(int))) == 0);
        lht_print(table);
    }
    {
        int x = 45;
        assert(lht_add(table, buffer_create((char *) &x, sizeof(int))) == 1);
        lht_print(table);
    }
    {
        int x = 42;
        assert(lht_add(table, buffer_create((char *) &x, sizeof(int))) == 1);
        lht_print(table);
    }
    {
        int x = 44;
        assert(lht_add(table, buffer_create((char *) &x, sizeof(int))) == 1);
        lht_print(table);
    }
    {
        int x = 51;
        assert(lht_add(table, buffer_create((char *) &x, sizeof(int))) == 0);
        lht_print(table);
    }


    lht_free(table);
}
//#endif