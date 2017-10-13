MOCK_PATH = runtimes/mock
RANDOM_PATH = runtimes/random

all: random_runtime mock_runtime server plug_server

random_runtime: force_look
	cd ${RANDOM_PATH}; make

mock_runtime: force_look
	cd ${MOCK_PATH}; make

server: force_look
	cd server; make

plug_server: plug_server_main.o
	gcc -g ${MOCK_PATH}/mock_runtime.o ${RANDOM_PATH}/random_runtime.o server/api_handlers.o server/server.o plug_server_main.o -o plug_server

plug_server_main.o: plug_server_main.c
	gcc -c -I../include plug_server_main.c -o plug_server_main.o

force_look:
	true

clean:
	rm -rf ${RANDOM_PATH}/*.o ${MOCK_PATH}/*.o ${MOCK_PATH}/mock_runner server/*.o *.o plug_server