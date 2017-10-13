#ifndef API_HANDLERS_H
#define API_HANDLERS_H

#include "language_runtime_api.h"

int handleInitialConfigurationsRequest(int peer_socket, language_runtime *api);
int handleFireableTransitionsFromRequest(int peer_socket, language_runtime *api);
int handleFireOneTransitionRequest(int peer_socket, language_runtime *api);

#endif /*API_HANDLERS_H*/