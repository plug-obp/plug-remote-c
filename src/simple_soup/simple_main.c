#include "ss_metamodel.h"
#include "ss_interpreter.h"

#include <stdlib.h>

int main(int argc, char**argv) {
    ss_soup *soup = ss_make_soup();

    int initial_size = 0;
    ss_state **initial_states = 0;

    ss_initial_configurations(soup, &initial_size, &initial_states);
    if (initial_size < 1 || initial_states == 0) {
        return 1;
    }

    ss_state *state = initial_states[0];
    char *fireables = (char *)malloc(soup->behaviors_size * sizeof(char));
    
    while (1) {
        print_state(state);

        ss_get_fireable_transitions(soup, state, fireables);

        //fire the first enabled transition
        for (int i=0; i<soup->behaviors_size; i++) {
            if (fireables[i]) {
                ss_fire_transition(soup, state, i);
            }
        }
    }

    ss_free_soup(soup);
    return 0;
}

