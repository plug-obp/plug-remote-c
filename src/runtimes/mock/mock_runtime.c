#include <stdlib.h>
#include <stdio.h>
#include "language_runtime_api.h"
#include "mock_runtime.h"

size_t mock_get_configuration_size() {
	return sizeof(int);
}

int mock_initial_configurations(int *outNumConfigurations, void ***outConfigurations) {
	int **result = malloc(2*sizeof(int*));
    if (result == 0) return -1;

    result[0] = malloc(sizeof(int));
    if (result[0] == 0) {
    	free(result);
    	return -1;
    }
    
    result[1] = malloc(sizeof(int));
    if (result[1] == 0) { 
    	free(result[0]);
    	free(result);
    	return -1;
    }
	
	result[0][0] = 42;
	result[1][0] = 43;
	*outNumConfigurations = 2;
	*outConfigurations = (void**)result;
	return 1;
}

int mock_fireable_transitions_from(void *inConfiguration, int *outNumTransitions, void ***outTransitions) {
	int current = *(int*)inConfiguration;

	switch (current) {
		case 42: {
			int **result = malloc(2*sizeof(int*));
	        if (result == 0) return -1;

	        result[0] = malloc(sizeof(int));
	        if (result[0] == 0) {
	        	free(result);
	        	return -1;
	        }
	        result[1] = malloc(sizeof(int));
	        if (result[1] == 0) {
	        	free(result[0]);
	        	free(result);
	        	return -1;
	        }
			
			result[0][0] = 1;
			result[1][0] = 2;
			*outNumTransitions = 2;
			*outTransitions = (void**)result;
	        break;
		}
		case 43: {
	        int **result = malloc(sizeof(int*));
	        if (result == 0) {
	        	return -1;
	        }
	        result[0] = malloc(sizeof(int));
	        if (result[0] == 0) {
	        	free(result);
	        	return -1;
	        }
	        result[0][0] = 3;
	        *outNumTransitions = 1;
	        *outTransitions = (void **) result;
	        break;
		}
	    default: {
	        int **result = malloc(sizeof(int*));
	        if (result == 0) {
	        	return -1;
	        }
	        result[0] = malloc(sizeof(int));
	        if (result[0] == 0) {
	        	free(result);
	        	return -1;
	        }

	        result[0][0] = 4;
	        *outNumTransitions = 1;
	        *outTransitions = (void **) result;
	    }
	}

	return 1;
}

int mock_fire_one_transition(void *inConfiguration, void *inTransition, int *outNumConfigurations, void ***outConfigurations) {
	int transition = *(int *) inTransition;

	int *target = malloc (sizeof(int));
	if (target == 0) return -1;
	switch (transition) {
		case 1:
		case 4:
			*target = 42;
            break;
		case 2:
			*target = 43;
            break;
		case 3:
			*target = 44;
            break;
        default: 
        	free(target);
        	return -1;
	}
	printf("(%d -> %d)\n", *(int*)inConfiguration, *target);

	*outNumConfigurations = 1;
	*outConfigurations = malloc(1*sizeof(int**));
	if (*outConfigurations == 0) {
        return -1;
    }
	*outConfigurations[0] = target;
	return 1;
}

void mock_free_configurations(int inNumConfigurations, void ***ioConfigurations) {
	for (int i=0; i<inNumConfigurations; i++) {
		free(*ioConfigurations[i]);
	}
	free(*ioConfigurations);
	*ioConfigurations = NULL;
}
void mock_free_transitions(int inNumTransitions, void ***ioTransitions) {
	for (int i=0; i<inNumTransitions; i++) {
		free(*ioTransitions[i]);
	}
	free(*ioTransitions);
	*ioTransitions = NULL;
}

language_runtime* mock_getRuntime() {
	language_runtime *runtime = malloc(sizeof(language_runtime));
	if (runtime == 0) {
		return 0;
	}

	runtime->opaque = 0;
	runtime->mGetConfigurationSize = mock_get_configuration_size;
	runtime->mGetTransitionSize = mock_get_configuration_size;
	runtime->mInitialConfigurations = mock_initial_configurations;
	runtime->mFireableTransitionsFrom = mock_fireable_transitions_from;
	runtime->mFireOneTransition = mock_fire_one_transition;
	runtime->mFreeConfigurations = mock_free_configurations;
	runtime->mFreeTransitions = mock_free_transitions;
	return runtime;
}

void mock_freeRuntime(language_runtime * runtime) {
	free(runtime);
}
