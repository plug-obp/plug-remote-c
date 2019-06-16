#include <stddef.h>

#include "buffer/buffer.h"
#include "open/open.h"
#include "hashtable/hashtable.h"
#include "driver.h"

int bfs(mc_automaton_t *in_automaton) {
    open_t *open = open_create(5, buffer_print);
    hashtable_t *closed = lht_new(10, buffer_callbacks);

    char *initial = 0;
    int initial_size = sizeof(int);
    char has_next = 0;
    do {
        in_automaton->m_initial_handler(
            in_automaton->m_opaque, 
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
            in_automaton->m_next_handler(
                in_automaton->m_opaque,
                current->data, &current->size,
                target, &target_size,
                &has_next);
            
            if (target == 0) continue; //no target was set

            buffer_t *target_buffer = buffer_create(target, target_size);
            if (!set_add(closed, target_buffer)) {
                add(open, target_buffer);
            }
        } while (has_next);
    }
    return 0;
}

int run_analysis(driver_t *in_driver_params) {
    return bfs(&in_driver_params->m_automaton);
}


