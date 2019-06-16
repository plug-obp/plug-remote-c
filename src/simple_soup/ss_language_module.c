#include "ss_language_module.h"
#include "ss_interpreter.h"

#include <string.h>

int ss_initial_configurations(void *opaque, int* outNumConfigurations, void*** outConfigurations) {
    ss_runtime_state *the_rstate = (ss_runtime_state *)opaque;
    int result = ss_get_initial_configuration(the_rstate);

    *outConfigurations = (void **)&the_rstate->m_state;
    *outNumConfigurations = 1;

    return result;
}
int ss_fireable_transitions(void *opaque, void * inConfiguration, int* outNumTransitions, void *** outTransitions) {
    ss_runtime_state *the_rstate = (ss_runtime_state *)opaque;
    
    memcpy(the_rstate->m_state, inConfiguration, sizeof(ss_state));
    int result = ss_get_fireable_transitions(the_rstate);
 
    *outTransitions = (void **)the_rstate->m_fireable_set;
    *outNumTransitions = the_rstate->m_fireable_size;
    return 0;
}
int ss_fire_one_transition(void *opaque, void *inConfiguration, void *inTransition, int* outNumConfigurations, void ***outConfigurations, void **outPayload) {
    ss_runtime_state *the_rstate = (ss_runtime_state *)opaque;
    
    memcpy(the_rstate->m_state, inConfiguration, sizeof(ss_state));
    int result = ss_fire_transition(the_rstate, (int)inTransition);

    *outNumConfigurations = 1;
    *outConfigurations = (void **)&the_rstate->m_state;
    *outPayload = 0;
    return 0;
}

obp2_transition_relation ss_transition_relation = {
    .m_module = 0,
    .m_initial_configurations = ss_initial_configurations,
    .m_fireable_transitions = ss_fireable_transitions,
	.m_fire_one_transition = ss_fire_one_transition
};