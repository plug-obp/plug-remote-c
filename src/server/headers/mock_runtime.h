#ifndef MOCK_RUNTIME_H
#define MOCK_RUNTIME_H

language_runtime *mock_getRuntime();
void mock_freeRuntime(language_runtime * runtime);

#endif /*MOCK_RUNTIME_H*/