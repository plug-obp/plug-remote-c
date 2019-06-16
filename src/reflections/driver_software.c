#include <stddef.h>

#include "buffer/buffer.h"
#include "open/open.h"
#include "hashtable/hashtable.h"
#include "driver.h"
#include "language_module/gve_adaptor.h"

int bfs(gve_context_t *io_context) {
    open_t *open = open_create(5, buffer_print);
    hashtable_t *closed = lht_new(10, buffer_callbacks);

    char *initial = 0;
    int initial_size = sizeof(int);
    char has_next = 0;
    do {
        gve_next_initial(
            io_context, 
            &initial, &initial_size, 
            &has_next);
        if (initial == 0) continue; //no initial was set
        open_add(open, buffer_create(initial, initial_size));
    } while (has_next);

    while (!open_empty(open)) {
        char has_next = 0;
        buffer_t *current = NULL;
        open_remove(open, (void **)&current);
        
        char *target = 0;
        int target_size = sizeof(int);
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
    return 0;
}

int run_analysis(driver_t *in_driver_params) {
    return bfs(in_driver_params->m_gve_context);
}


