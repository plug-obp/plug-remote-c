#include <time.h>
#include <string.h>
#include "language_runtime_api.h"
#include "mock_runtime.h"

int main(int argc, char **argv) {
	srand((unsigned int)time(NULL));

	language_runtime *api = mock_getRuntime();

	void ** configurations = 0;
	int numConfigurations = 0;
	api->mInitialConfigurations(&numConfigurations, &configurations);

	int choice = rand()%numConfigurations;
	void * sourceConfiguration = malloc(api->mGetConfigurationSize());
	memcpy(sourceConfiguration, configurations[choice], api->mGetConfigurationSize());

	int iterations = 500;
	while (iterations > 0) {
		void **transitions = 0;
		int numTransitions = 0;
		int numTargetConfigurations = 0;
		void **targetConfigurations = 0;

		api->mFireableTransitionsFrom(sourceConfiguration, &numTransitions, &transitions);

		choice = rand()%numTransitions;
		api->mFireOneTransition(sourceConfiguration, transitions[choice], &numTargetConfigurations, &targetConfigurations);
		
		free(sourceConfiguration);

		for (int i=0; i<numTransitions; i++) {
			free(transitions[i]);
		}
		free(transitions);

		sourceConfiguration = targetConfigurations[0];
		iterations--;
	}
	free(sourceConfiguration);

	for (int i=0; i<numConfigurations; i++) {
		free(configurations[i]);
	}
	free(configurations);

	free(api);

	return 1;
}
