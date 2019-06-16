#ifndef GVE_ADAPTOR
#define GVE_ADAPTOR
#include "language_module.h"

typedef struct iterator_s iterator_t;

struct gve_context_s {
    obp2_language_runtime *m_runtime;
    iterator_t *m_initial_iterator;
    iterator_t *m_next_iterator;
};
typedef struct gve_context_s gve_context_t;

gve_context_t *gve_create_context(obp2_language_runtime *runtime);
void gve_free_context(gve_context_t *context);
int gve_initial_handler(gve_context_t *context, char **out_target, int *io_target_size, char *out_has_next);
int gve_next_handler(gve_context_t *context, char *in_source, int in_source_size, char **out_target, int *io_target_size, char *out_has_next);

#endif //GVE_ADAPTOR