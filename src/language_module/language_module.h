#ifndef LANGUAGE_MODULE_H
#define LANGUAGE_MODULE_H

typedef struct obp2_language_module_s obp2_language_module;

struct obp2_transition_relation_s {
    obp2_language_module *m_module;

    int (*m_initial_configurations)(void *opaque, int* outNumConfigurations, void*** outConfigurations);
	int (*m_fireable_transitions)(void *opaque, void * inConfiguration, int* outNumTransitions, void *** outTransitions);
	int (*m_fire_one_transition)(void *opaque, void *inConfiguration, void *inTransition, int* outNumConfigurations, void ***outConfigurations, void **outPayload);
};
typedef struct obp2_transition_relation_s obp2_transition_relation;

typedef char bool;
struct obp2_atom_evaluator_s {
    obp2_language_module *m_module;

    int (*m_register_atomic_propositions)(void *opaque, int inSize, char **inPropositions, int *outSize, int **outIndices);
    int (*m_atomic_proposition_valuations)(void *opaque, void *inConfiguration, int *outSize, bool **outValuations);
    int (*m_extended_atomic_proposition_valuations)(void *opaque, void *inSource, void *inFireable, void *inPayload, void *inTarget, int *outSize, bool **outValuations);
};
typedef struct obp2_atom_evaluator_s obp2_atom_evaluator;

struct obp2_marshaller_s {
    obp2_language_module *m_module;

    int (*m_serialize_configuration)(void *opaque, void * inConfiguration, int* outSize, char **outData);
    int (*m_deserialize_configuration)(void *opaque, int inSize, char *inData, void **outConfiguration);
    int (*m_serialize_transition)(void *opaque, void * inTransition, int* outSize, char **outData);
    int (*m_deserialize_transition)(void *opaque, int inSize, char *inData, void ** outTransition);
    int (*m_serialize_payload)(void *opaque, void * inPayload, int*outSize, char **outData);
    int (*m_deserialize_payload)(void *opaque, int inSize, char * inData, void **outPayload);
};

typedef struct obp2_marshaller_s obp2_marshaller;

typedef struct obp2_tree_item_s obp2_tree_item;
struct obp2_tree_item_s {
    char *type;
    char *name;
    char *icon;
    obp2_tree_item *children;
};

struct obp2_view_s {
    obp2_language_module *m_module;

    int (*m_configuration_view)(void *opaque, void *inConfiguration, obp2_tree_item *view);
    int (*m_fireable_view)(void *opaque, void *inFireable, obp2_tree_item *view);
    int (*m_payload_view)(void *opaque, void *inPayload, obp2_tree_item *view);
};
typedef struct obp2_view_s obp2_view;

struct obp2_language_module_s {
    obp2_transition_relation transition_relation;
    obp2_atom_evaluator atom_evaluator;
    obp2_marshaller marshaller;
    obp2_view view;
};
typedef struct obp2_language_module_s obp2_language_module;

struct obp2_language_runtime_s {
    void *m_runtime_data;
    obp2_language_module m_language_module;
};
typedef struct obp2_language_runtime_s obp2_language_runtime;

obp2_language_runtime *obp2_create_runtime();
int obp2_free_runtime(obp2_language_runtime* runtime); 

#endif /*LANGUAGE_MODULE_H*/