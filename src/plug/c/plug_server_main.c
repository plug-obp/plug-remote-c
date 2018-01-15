#include "language_runtime_api.h"
#include "server.h"
#include "mock_runtime.h"

int main(int argc, char **argv) {
	language_runtime *api = mock_getRuntime();
	int ret = start_server(atol(argv[1]), api);
	mock_freeRuntime(api);
	return ret;
}
