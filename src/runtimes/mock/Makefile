mock_runner: mock_runtime.o mock_runner.o
	gcc -g mock_runtime.o mock_runner.o -o mock_runner

mock_runtime.o: mock_runtime.c
	gcc -I../../../include -g -c mock_runtime.c -o mock_runtime.o

mock_runner.o: mock_runner.c
	gcc -I../../../include -g -c mock_runner.c -o mock_runner.o