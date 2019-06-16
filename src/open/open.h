
typedef struct open_s open_t;

typedef void (*PrintCb_t)(void *data);

#define OK 0
#define OPEN_FULL 1
#define OPEN_EMPTY 2

open_t * open_create(int size, PrintCb_t printer);
int open_add(open_t *self, void *in_data);
int open_remove(open_t *self, void **out_data);
int open_peek(open_t *self, void **out_data);
void open_free(open_t *self);
void open_print(open_t *self);
char open_empty(open_t *self);
char open_full(open_t *self);

