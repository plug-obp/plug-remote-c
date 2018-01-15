#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "language_runtime_api.h"
#include "random_runtime.h"

#define MAX_TRANSITIONS 20
#define GB 1073741824
#define CONF_SIZE 5
#define CHANGE_SIZE CONF_SIZE


char *allocate_new_configuration(int size) {
    char * r = (char *)malloc(size * sizeof(char));
    if (r == 0) return 0;
    for (int i =0 ; i<size; i++) {
        r[i] = 1;
    }
    return r;
}


size_t random_get_configuration_size() {
	return CONF_SIZE*sizeof(char);
}

size_t random_get_transition_size() {
	return sizeof(int);
}

int random_initial_configurations(int *outNumConfigurations, void ***outConfigurations) {
    int numConfigurations = 1;
	char **configurations = malloc(numConfigurations*sizeof(void*));
	if (configurations == 0) {
		return -1;
	}
	configurations[0] = allocate_new_configuration(CONF_SIZE);
    if (configurations[0] == NULL) {
        free(configurations);
        return -1;
    }
	*outNumConfigurations = numConfigurations;
    *outConfigurations = (void **)configurations;
	return 0;
}

int random_fireable_transitions_from(void *conf, int *nbTargets, void ***outTargets) {
    int nb = (rand() % (MAX_TRANSITIONS-1)) + 1;
    if (nb == 0) return 0;

    int **targets = malloc(nb * sizeof(int *));
    if (targets == 0) {
    	return -1;
    }
    
    for (int i = 0; i < nb; i++) {
        targets[i] = malloc(sizeof(int));
        if (targets[i] == 0) {
            free(targets);
        	return -1;
        }
        
        //alterate the configuration
        int idx = rand() % CHANGE_SIZE;

        targets[i][0] = idx;
    }
    *nbTargets = nb;
    *outTargets = (void **)targets;
    return 0;
}

int random_fire_one_transition(void *inConfiguration, void *inTransition, int *outNumConfigurations, void ***outConfigurations) {
    *outNumConfigurations = 1;
    *outConfigurations = malloc(1*sizeof(int**));
    if (*outConfigurations == 0) {
        return -1;
    }

    *outConfigurations[0] = malloc(CONF_SIZE * sizeof(char));
    if (*outConfigurations[0] == 0) {
        return -1;
    }

	memcpy(*outConfigurations[0], inConfiguration, CONF_SIZE);
	(*(char**)outConfigurations)[*(int*)inTransition] = !(*(char**)outConfigurations)[*(int*)inTransition];
	return 0;
}

void random_free_configurations(int inNumConfigurations, void ***ioConfigurations) {
    for (int i=0; i<inNumConfigurations; i++) {
        free(*ioConfigurations[i]);
    }
    free(*ioConfigurations);
    *ioConfigurations = NULL;
}
void random_free_transitions(int inNumTransitions, void ***ioTransitions) {
    for (int i=0; i<inNumTransitions; i++) {
        free(*ioTransitions[i]);
    }
    free(*ioTransitions);
    *ioTransitions = NULL;
}

language_runtime* random_getRuntime() {
	srand((unsigned int)time(NULL));
	language_runtime *runtime = malloc(sizeof(language_runtime));
	if (runtime == 0) {
		return 0;
	}

	runtime->opaque = 0;
	runtime->mGetConfigurationSize 		= random_get_configuration_size;
	runtime->mGetTransitionSize 		= random_get_transition_size;
	runtime->mInitialConfigurations 	= random_initial_configurations;
	runtime->mFireableTransitionsFrom 	= random_fireable_transitions_from;
	runtime->mFireOneTransition 		= random_fire_one_transition;
    runtime->mFreeConfigurations        = random_free_configurations;
    runtime->mFreeTransitions           = random_free_transitions;
	return runtime;
}

void random_freeRuntime(language_runtime * runtime) {
    free(runtime);
}
