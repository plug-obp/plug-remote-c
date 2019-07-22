#include <stddef.h>
#include <stdio.h>

#include "buffer/buffer.h"
#include "open/open.h"
#include "hashtable/hashtable.h"
#include "driver.h"
#include "language_module/gve_adaptor.h"

int bfs(gve_context_t *io_context, int open_cap, int closed_cap) {
    open_t *open = open_create(open_cap, buffer_print);
    hashtable_t *closed = lht_new(closed_cap, buffer_callbacks);

    char *initial = 0;
    int initial_size = 0;
    char has_next = 0;
    do {
        gve_next_initial(
            io_context, 
            &initial, &initial_size, 
            &has_next);
        if (initial == 0) continue; //no initial was set
        
        buffer_t *buffer = buffer_create(initial, initial_size);
        if (!lht_add(closed, buffer)) {
            open_add(open, buffer);
        }
    } while (has_next);

    while (!open_empty(open)) {
        buffer_t *current = NULL;
        open_remove(open, (void **)&current);
        
        char has_next = 0;
        char *target = 0;
        int target_size = 0;
        do {
            gve_next_target(
                io_context,
                current->data, current->size,
                &target, &target_size,
                &has_next);
            
            if (target == 0) continue; //no target was set

            buffer_t *target_buffer = buffer_create(target, target_size);
            if (!lht_add(closed, target_buffer)) {
                open_add(open, target_buffer);
            } 
        } while (has_next);
    }
    printf("number of configurations %d\n", lht_size(closed));
    //lht_print(closed);
    lht_free(closed);
    open_free(open);
    return 0;
}

int run_analysis(driver_t *in_driver_params) {
    return bfs(in_driver_params->m_gve_context, in_driver_params->m_open_capacity, in_driver_params->m_closed_capacity);
}


