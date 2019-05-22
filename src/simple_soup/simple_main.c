#include "ss_metamodel.h"
#include "ss_interpreter.h"

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char**argv) {
    ss_state state;

    ss_runtime_state the_runtime_state;
    the_runtime_state.m_soup  = ss_make_soup();
    the_runtime_state.m_state = &state;
    the_runtime_state.m_fireable_size = the_runtime_state.m_soup->behaviors_size;
    the_runtime_state.m_fireable_set = alloca(the_runtime_state.m_fireable_size * sizeof(int));

    ss_get_initial_configuration(&the_runtime_state);
    
    int steps = 10;
    while (steps > 0) {
        print_state(the_runtime_state.m_state);

        ss_get_fireable_transitions(&the_runtime_state);

        //fire the first enabled transition, and break
        if (the_runtime_state.m_fireable_size < 1) break; //if no fireable end the execution
        ss_fire_transition(&the_runtime_state, the_runtime_state.m_fireable_set[0]);
        steps--;
    }

#ifdef SS_DYNAMIC
    ss_free_soup(the_runtime_state.m_soup);
    
    printf("freed dynamically allocated model\n");
#endif
    return 0;
}

