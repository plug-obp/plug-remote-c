#include <stddef.h>
#include <stdlib.h>
#include "ss_language_module.h"
#include "ss_interpreter.h"

#include <string.h>

int ss_initial_configurations(void *opaque, int* outNumConfigurations, void*** outConfigurations) {
    ss_runtime_state *the_rstate = (ss_runtime_state *)opaque;
    int result = ss_get_initial_configuration(the_rstate);

    *outConfigurations = malloc(sizeof(void *));
    (*outConfigurations)[0] = malloc(sizeof(ss_state));
    memcpy((*outConfigurations)[0],the_rstate->m_state, sizeof(ss_state));
    *outNumConfigurations = 1;

    return result;
}
int ss_fireable_transitions(void *opaque, void * inConfiguration, int* outNumTransitions, void *** outTransitions) {
    ss_runtime_state *the_rstate = (ss_runtime_state *)opaque;
    
    memcpy(the_rstate->m_state, inConfiguration, sizeof(ss_state));
    ss_get_fireable_transitions(the_rstate);
 
    int **transitions = malloc(the_rstate->m_fireable_size * sizeof(int*));
    for (int i = 0; i < the_rstate->m_fireable_size; i++) {
        transitions[i] = malloc(sizeof(int));
        *(transitions[i]) = the_rstate->m_fireable_set[i];
    }
    *outTransitions = ((void **) transitions);
    *outNumTransitions = the_rstate->m_fireable_size;
    return 0;
}
int ss_fire_one_transition(void *opaque, void *inConfiguration, void *inTransition, int* outNumConfigurations, void ***outConfigurations, void **outPayload) {
    ss_runtime_state *the_rstate = (ss_runtime_state *)opaque;
    
    memcpy(the_rstate->m_state, inConfiguration, sizeof(ss_state));
    ss_fire_transition(the_rstate, *(int *)inTransition);

    *outConfigurations = malloc(sizeof(void *));
    (*outConfigurations)[0] = malloc(sizeof(ss_state));
    memcpy((*outConfigurations)[0], the_rstate->m_state, sizeof(ss_state));
    *outNumConfigurations = 1;
    *outPayload = 0;
    return 0;
}

int ss_serialize_configuration(void *opaque, void * inConfiguration, int* outSize, char **outData) {
    
    *outSize = sizeof(ss_state);
    *outData = malloc(sizeof(ss_state));
    if (*outData == NULL) {
        return 1;
    }
    memcpy(*outData, inConfiguration, *outSize);
    return 0;
}
int ss_deserialize_configuration(void *opaque, int inSize, char *inData, void **outConfiguration){
    *outConfiguration = malloc(inSize);
    memcpy(*outConfiguration, inData, inSize);
    return 0;
}
int ss_serialize_transition(void *opaque, void * inTransition, int* outSize, char **outData){

    *outSize = sizeof(int);
    *outData = malloc(sizeof(int));
    memcpy(*outData, inTransition, *outSize);
    return 0;
}
int ss_deserialize_transition(void *opaque, int inSize, char *inData, void ** outTransition){
    *outTransition = malloc(inSize);
    memcpy(*outTransition, inData, inSize);
    return 0;
}
int ss_serialize_payload(void *opaque, void * inPayload, int*outSize, char **outData){
    *outSize = 0;
    *outData = NULL;
    return 0;
}
int ss_deserialize_payload(void *opaque, int inSize, char * inData, void **outPayload){

    *outPayload = NULL;
    return 0;
}

ss_runtime_state the_runtime_state;

obp2_language_runtime ss_language_runtime = {
    .m_runtime_data = &the_runtime_state,
    .m_language_module = {
        .transition_relation = {
            .m_module = 0,
            .m_initial_configurations = ss_initial_configurations,
            .m_fireable_transitions = ss_fireable_transitions,
            .m_fire_one_transition = ss_fire_one_transition
        },
        .atom_evaluator = NULL,
        .marshaller = {
            .m_module = NULL,
            .m_serialize_configuration = ss_serialize_configuration,
            .m_deserialize_configuration = ss_deserialize_configuration,
            .m_serialize_transition = ss_serialize_transition,
            .m_deserialize_transition = ss_deserialize_transition,
            .m_serialize_payload = ss_serialize_payload,
            .m_deserialize_payload = ss_deserialize_payload
        },
        .view = NULL
    }
};

obp2_language_runtime* obp2_create_runtime() {
    ss_state *state = malloc(sizeof(ss_state));

    the_runtime_state.m_soup  = ss_make_soup();
    the_runtime_state.m_state = state;
    the_runtime_state.m_fireable_size = the_runtime_state.m_soup->behaviors_size;
    the_runtime_state.m_fireable_set = malloc(the_runtime_state.m_fireable_size * sizeof(int));

    return &ss_language_runtime;
}
