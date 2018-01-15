#include "language_runtime_api.h"
#include "server.h"
#include "random_runtime.h"

int main(int argc, char **argv) {
	language_runtime *api = random_getRuntime();
	int ret = start_server(atol(argv[1]), api);
	random_freeRuntime(api);
	return ret;
}

