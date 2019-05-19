#ifndef LANGUAGE_MODULE_H
#define LANGUAGE_MODULE_H

typedef struct obp2_language_module_s obp2_language_module;

struct obp2_transition_relation_s {
    obp2_language_module *module;

    int (*m_initial_configurations)(int* outNumConfigurations, void*** outConfigurations);
	int (*m_fireable_transitions)(void * inConfiguration, int* outNumTransitions, void *** outTransitions);
	int (*m_fire_one_transition)(void *inConfiguration, void *inTransition, int* outNumConfigurations, void ***outConfigurations, void **outPayload);
};
typedef struct obp2_transition_relation_s obp2_transition_relation;


struct obp2_atom_evaluator_s {
    obp2_language_module *module;

    int (*m_register_atomic_propositions)(int inSize, char **inPropositions, int *outSize, int **outIndices);
    int (*m_atomic_proposition_valuations)(void *inConfiguration, int *outSize, bool **outValuations);
    int (*m_extended_atomic_proposition_valuations)(void *inSource, void *inFireable, void *inPayload, void *inTarget, int *outSize, bool **outValuations);
};
typedef struct obp2_atom_evaluator_s obp2_atom_evaluator;

struct obp2_marshaller_s {
    obp2_language_module *module;

    int (*m_serialize_configuration)(void * inConfiguration, int* outSize, char **outData);
    int (*m_deserialize_configuration)(int inSize, char *inData, void **outConfiguration);
    int (*m_serialize_transition)(void * inTransition, int* outSize, char **outData);
    int (*m_deserialize_transition)(int inSize, char *inData, void ** outTransition);
    int (*m_serialize_payload)(void * inPayload, int*outSize, char **outData);
    int (*m_deserialize_payload)(int inSize, char * inData, void **outPayload);
};

typedef struct obp2_marshaller_s obp2_marshaller;

struct obp2_view_s {
    obp2_language_module *module;

    int (*m_configuration_view)();
    int (*m_fireable_view)();
    int (*m_payload_view)();
};
typedef struct obp2_view_s obp2_view;

struct obp2_language_module_s {
    obp2_transition_relation transition_relation;
    obp2_atom_evaluator atom_evaluator;
    obp2_marshaller marshaller;
    obp2_view view;
};

#endif /*LANGUAGE_MODULE_H*/