#include <netinet/in.h>
#include <sys/socket.h>
#include <stdio.h>
#include <unistd.h>
#include "language_runtime_api.h"
#include "server.h"
#include "api_handlers.h"

typedef int (*api_callback_t)(int peer_socket, language_runtime* api);
api_callback_t handlers[] = {
	handleInitialConfigurationsRequest,
	handleFireableTransitionsFromRequest,
	handleFireOneTransitionRequest
};

char readRequest(int peer_socket) {
	char data[2] = {-1,-1};
	if (read(peer_socket, &data, 2) < 2) {
		return -1;
	}
	if (data[0] != 1) /*invalid request*/ return -1;
	return data[1];
}

int start_server(int port, language_runtime * api) {
	int server_socket, peer_socket;
	struct sockaddr_in server_address, peer_address;
	socklen_t peer_address_size;

	if ((server_socket = socket(AF_INET, SOCK_STREAM, 0))==-1){
    	fprintf(stderr,"socket err\n");
    	return -1;
  	}

	server_address.sin_family = AF_INET;
	server_address.sin_addr.s_addr = htonl(INADDR_ANY);
	server_address.sin_port = htons(port);
	
	if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(struct sockaddr_in)) == -1) {
		fprintf(stderr,"socket bind err\n");
		return -1;
	}

	if(listen(server_socket, 1) == -1){
		fprintf(stderr,"socket listen err\n");
		return -1;
  	}

	peer_address_size = sizeof(struct sockaddr_in);
  	if ((peer_socket = accept(server_socket, (struct sockaddr *)&peer_address, &peer_address_size)) == -1) {
  		fprintf(stderr,"socket accept err\n");
		return -1;
  	}

  	char requestID;
	if ((requestID = readRequest(peer_socket)) < 0) {
		return -1;
	}

  	while (requestID >= 1 && requestID <=3) {
	  	if (handlers[requestID-1](peer_socket, api) == -1) {
	  		fprintf(stderr, "handler error\n");
	  		return -1;
	  	} 

	  	if ((requestID = readRequest(peer_socket)) < 0) {
			return -1;
		}
	}

  	close(peer_socket);
  	close(server_socket);
  	return 0;
}
