all: server.o api_handlers.o

server.o: server.c
	gcc -I../../include -g -c server.c -o server.o
api_handlers.o: api_handlers.c
	gcc -I../../include -g -c api_handlers.c -o api_handlers.o
