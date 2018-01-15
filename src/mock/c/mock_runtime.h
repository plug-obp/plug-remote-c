#ifndef MOCK_RUNTIME_H
#define MOCK_RUNTIME_H

#include "language_runtime_api.h"

language_runtime *mock_getRuntime();
void mock_freeRuntime(language_runtime * runtime);

#endif /*MOCK_RUNTIME_H*/
