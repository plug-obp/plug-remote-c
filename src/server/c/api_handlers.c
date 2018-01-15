#include <stdio.h>
#include <unistd.h>
#include "language_runtime_api.h"

int handleInitialConfigurationsRequest(int peer_socket, language_runtime *api) {
	printf("h_initial\n");

	if (api==NULL) return -1;

	int numConfigurations = 0;
	void **configurations = 0;

	if (api->mInitialConfigurations(&numConfigurations, &configurations) == -1) {
		return -1;
	}

	if (write(peer_socket, &numConfigurations, sizeof(int)) != sizeof(int)) {
		api->mFreeConfigurations(numConfigurations, &configurations);
		return -1;
	}

	size_t configurationSize = api->mGetConfigurationSize();

	if (write(peer_socket, &configurationSize, sizeof(size_t)) != sizeof(size_t)) {
		api->mFreeConfigurations(numConfigurations, &configurations);
		return -1;
	}

	for (int i = 0; i<numConfigurations;i++) {
		if (write(peer_socket, configurations[i], configurationSize) != configurationSize) {
			api->mFreeConfigurations(numConfigurations, &configurations);
			return -1;
		}
	}

	return 0;
}
int handleFireableTransitionsFromRequest(int peer_socket, language_runtime *api) {
	printf("h_fireables\n");

	if (api == NULL) return -1;

	size_t configurationSize = api->mGetConfigurationSize();
	void *configuration = malloc(configurationSize);

	if (configuration == NULL) return -1;

	if (read(peer_socket, configuration, configurationSize) != configurationSize) {
		free(configuration);
		return -1;
	}

	int numTransitions = 0;
	void **transitions = 0;

	if (api->mFireableTransitionsFrom(configuration, &numTransitions, &transitions) == -1) {
		free(configuration);
		return -1;
	}

	if (write(peer_socket, &numTransitions, sizeof(int)) != sizeof(int)) {
		free(configuration);
		api->mFreeTransitions(numTransitions, &transitions);
		return -1;
	}

	size_t transitionSize = api->mGetTransitionSize();

	if (write(peer_socket, &transitionSize, sizeof(size_t)) != sizeof(size_t)) {
		free(configuration);
		api->mFreeTransitions(numTransitions, &transitions);
		return -1;
	}

	for (int i = 0; i<numTransitions;i++) {
		if (write(peer_socket, transitions[i], transitionSize) != transitionSize) {
			free(configuration);
			api->mFreeTransitions(numTransitions, &transitions);
			return -1;
		}
	}

	return 0;
}
int handleFireOneTransitionRequest(int peer_socket, language_runtime *api) {
	printf("h_fire\n");

	if (api == NULL) return -1;

	size_t configurationSize = api->mGetConfigurationSize();
	void *sourceConfiguration = malloc(configurationSize);
	if (sourceConfiguration == NULL) return -1;

	if (read(peer_socket, sourceConfiguration, configurationSize) != configurationSize) {
		free(sourceConfiguration);
		return -1;
	}

	size_t transitionSize = api->mGetTransitionSize();
	void *transition = malloc(transitionSize);
	if (transition == NULL) {
		free(sourceConfiguration);
		return -1;
	}

	if (read(peer_socket, transition, transitionSize) != transitionSize) {
		free(sourceConfiguration);
		free(transition);
		return -1;
	}

	int numTargetConfigurations;
	void** targetConfigurations;
	
	if (api->mFireOneTransition(sourceConfiguration, transition, &numTargetConfigurations, &targetConfigurations) == -1) {
		free(sourceConfiguration);
		free(transition);
		return -1;
	}

	if (write(peer_socket, &numTargetConfigurations, sizeof(int)) != sizeof(int)) {
		free(sourceConfiguration);
		free(transition);
		api->mFreeConfigurations(numTargetConfigurations, &targetConfigurations);
		return -1;
	}

	if (write(peer_socket, &configurationSize, sizeof(size_t)) != sizeof(size_t)) {
		free(sourceConfiguration);
		free(transition);
		api->mFreeConfigurations(numTargetConfigurations, &targetConfigurations);
		return -1;
	}

	for (int i = 0; i<numTargetConfigurations;i++) {
		if (write(peer_socket, targetConfigurations[i], configurationSize) != configurationSize) {
			free(sourceConfiguration);
			free(transition);
			api->mFreeConfigurations(numTargetConfigurations, &targetConfigurations);
			return -1;
		}
	}

	return 0;
}
