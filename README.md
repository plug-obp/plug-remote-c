# plug-remote-c

```c
struct language_runtime_s {
	void * opaque;
	//size API
	size_t (*mGetConfigurationSize)();
	size_t (*mGetTransitionSize)();
	//exploration API
	int (*mInitialConfigurations)(int* outNumConfigurations, void *** outConfigurations);
	int (*mFireableTransitionsFrom)(void * inConfiguration, int* outNumTransitions, void *** outTransitions);
	int (*mFireOneTransition)(void *inConfiguration, void *inTransition, int* outNumConfigurations, void ***outConfigurations);
	//memory management helpers
	void (*mFreeConfigurations)(int inNumConfigurations, void ***ioConfigurations);
	void (*mFreeTransitions)(int inNumTransitions, void ***ioTransitions);
};
```
