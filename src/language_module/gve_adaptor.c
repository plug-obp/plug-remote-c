#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "buffer/buffer.h"
#include "language_module.h"
#include "gve_adaptor.h"

struct iterator_s {
    void **table;
    char free_elements; //1 if the table elements can be freed, 0 if not
    int table_size;
    int index;
    iterator_t *child_iterator;
};

void iterator_reset(iterator_t *iterator) {
    if (iterator->free_elements) {
        for (int i=0; i<iterator->table_size; i++) {
            free(iterator->table[i]);
        }
    }
    free(iterator->table);
    iterator->index = 0;
    iterator->table_size = 0;

    iterator_t *current = iterator->child_iterator;
    while (current != NULL) {
        iterator_reset(current);
        current = current->child_iterator;
    }
}

gve_context_t *gve_create_context(obp2_language_runtime *runtime) {
    gve_context_t *context = malloc(sizeof(gve_context_t));
    context->m_runtime = runtime;
    context->m_initial_iterator = NULL;
    context->m_next_iterator = NULL;
    return context;
}

void gve_free_context(gve_context_t *context) {
    if (context->m_initial_iterator != NULL) {
        iterator_reset(context->m_initial_iterator);
        free(context->m_initial_iterator);
    }
    if (context->m_next_iterator != NULL) {
        iterator_reset(context->m_next_iterator);
        free(context->m_next_iterator);
    }
    free(context);
}

int gve_next_initial(gve_context_t *io_context, char **out_target, int *io_target_size, char *out_has_next) {
    iterator_t *iterator = io_context->m_initial_iterator;
    obp2_language_runtime *runtime = io_context->m_runtime;

    if (iterator == NULL) {
        int numInitial = 0;
        void **configurations = NULL;
        runtime->m_language_module.transition_relation.m_initial_configurations(runtime->m_runtime_data, &numInitial, &configurations);

        if (configurations == NULL || numInitial == 0) {
            *out_target = NULL;
            *io_target_size = 0;
            *out_has_next = 0;
            return 0;
        }

        iterator = malloc(sizeof(iterator_t));
        iterator->table = configurations;
        iterator->table_size = numInitial;
        iterator->index = 0;
        iterator->child_iterator = NULL;
        iterator->free_elements = 1;

        io_context->m_initial_iterator = iterator;
    }

    if (iterator->index >= iterator->table_size) {
        *out_target = NULL;
        *io_target_size = 0;
        *out_has_next = 0;
        return 0;
    }

    int target_size = 0;
    char *target = 0;
    runtime->m_language_module.marshaller
        .m_serialize_configuration(
            runtime->m_runtime_data, 
            iterator->table[iterator->index],
            &target_size,
            &target);
    
    iterator->index++;
    *out_has_next = 0;
    if (iterator->index >= iterator->table_size) {
        iterator_reset(iterator);
        free(iterator);
        io_context->m_initial_iterator = NULL;
    } else {
        *out_has_next = 1;
    }

    if (*io_target_size != 0 && *io_target_size < target_size) {
        printf("initial_handler: io_target_size < target_size\n");
        return 1; //the language returned a target bigger than the max accepted
    }
    *io_target_size = target_size;
    *out_target = target;
    return 0;
}

int next_target(obp2_language_runtime *runtime, iterator_t **io_iterator, void *source, void *fireable, char **out_target, int *io_target_size, char *out_has_next);

int gve_next_target(gve_context_t *io_context, char *in_source, int in_source_size, char **out_target, int *io_target_size, char *out_has_next) {
    iterator_t *iterator = io_context->m_next_iterator;
    obp2_language_runtime *runtime = io_context->m_runtime;

    void *source = NULL;
    runtime->m_language_module.marshaller.m_deserialize_configuration(runtime->m_runtime_data, in_source_size, in_source, &source);

    if (iterator == NULL) {
        int numFireables = 0;
        void **fireables = NULL;
        runtime->m_language_module.transition_relation
            .m_fireable_transitions(
                runtime->m_runtime_data,
                source,
                &numFireables,
                &fireables);

        if (fireables == NULL) {
            *out_target = NULL;
            *io_target_size = 0;
            *out_has_next = 0;
        }

        iterator = malloc(sizeof(iterator_t));
        iterator->table = fireables;
        iterator->table_size = numFireables;
        iterator->index = 0;
        iterator->child_iterator = NULL;
        iterator->free_elements = 1;

        io_context->m_next_iterator = iterator;
    }

    if (iterator->index >= iterator->table_size) {
        *out_target = NULL;
        *io_target_size = 0;
        *out_has_next = 0;
        return 0;
    }

    char has_next = 0;
    do {
        int result = 0;
        if ((result = next_target(runtime, &iterator->child_iterator, source, iterator->table[iterator->index], out_target, io_target_size, &has_next)) != 0) {
            return result;
        }
        if (!has_next) {
            iterator->index++;
            if (iterator->index >= iterator->table_size) {
                iterator_reset(iterator);
                free(iterator);
                io_context->m_next_iterator = NULL;
                *out_has_next = 0;
                return 0;
            }
        }
        
    } while (*out_target == NULL);

    *out_has_next = 0;
    if (has_next || iterator->index < iterator->table_size) {
        *out_has_next = 1;
    }

    return 0;
}

int next_target(obp2_language_runtime *runtime, iterator_t **io_iterator, void *source, void *fireable, char **out_target, int *io_target_size, char *out_has_next) {
    iterator_t *iterator = *io_iterator;

    if (iterator == NULL) {
        int numTargets = 0;
        void **targets = NULL;
        void *payload = NULL;
        runtime->m_language_module.transition_relation
            .m_fire_one_transition(runtime->m_runtime_data, source, fireable, &numTargets, &targets, &payload);

        if (targets == NULL || numTargets == 0) {
            *out_target = NULL;
            *io_target_size = 0;
            *out_has_next = 0;
            return 0;
        }

        iterator = malloc(sizeof(iterator_t));
        iterator->table = targets;
        iterator->table_size = numTargets;
        iterator->index = 0;
        iterator->child_iterator = NULL;
        iterator->free_elements = 1;

        *io_iterator = iterator;
    }

    if (iterator->index >= iterator->table_size) {
        *out_target = NULL;
        *io_target_size = 0;
        *out_has_next = 0;
        return 0;
    }

    int target_size = 0;
    char *target = 0;
    runtime->m_language_module.marshaller
        .m_serialize_configuration(
            runtime->m_runtime_data, 
            iterator->table[iterator->index],
            &target_size,
            &target);
    
    iterator->index++;
    *out_has_next = 0;
    if (iterator->index >= iterator->table_size) {
        iterator_reset(iterator);
        free(iterator);
        *io_iterator = NULL;
    } else {
        *out_has_next = 1;
    }

    if (*io_target_size != 0 && *io_target_size < target_size) {
        printf("next_target: io_target_size < target_size\n");
        return 1; //the language returned a target bigger than the max accepted
    }
    *io_target_size = target_size;
    *out_target = target;
    return 0;
}
