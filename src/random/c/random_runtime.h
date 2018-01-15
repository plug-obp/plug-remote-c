#ifndef RANDOM_RUNTIME_H
#define RANDOM_RUNTIME_H

#include "language_runtime_api.h"

language_runtime *random_getRuntime();
void random_freeRuntime(language_runtime * runtime);

#endif /*RANDOM_RUNTIME_H*/
