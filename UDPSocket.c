#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <arpa/inet.h>

#include "UDPSocket.h"



UDPSocket::UDPSocket(char* ip, unsigned short port) {
	mBuffer = new char[1000];
	mSocketFD = new int;
	bindSocket(ip, port);
}

void UDPSocket::bindSocket(char* ip, unsigned short port) {
	struct sockaddr_in bindAddr;

	//Create our socket
	*mSocketFD = socket(AF_INET, SOCK_DGRAM, 0);
    if (*mSocketFD < 0) 
    {
    	fprintf(stderr, "Error in socket creation.");
    	//TODO: Add exit here.
   	}

   	//Assemble our binding data
   	bindAddr.sin_family = AF_INET;
   	inet_pton(AF_INET, "127.0.0.1", &bindAddr.sin_addr);
   	bindAddr.sin_port = htons(port);

   	//Bind our socket
   	if (bind(*mSocketFD, (struct sockaddr *) &bindAddr, sizeof(bindAddr)) < 0) {
   		fprintf(stderr, "Error while binding.");
   		//TODO: Add exit
   	}
}

char* UDPSocket::listen() {
	printf("here");
	struct sockaddr cliAddr;
	int n;
	socklen_t len;

	len = sizeof(cliAddr);
	n = recvfrom(*mSocketFD, mBuffer, 1000, 0, (struct sockaddr*) &cliAddr, &len);
	return mBuffer;	
}

UDPSocket::~UDPSocket() {
	printf("Hit destructor.\n");
	delete mSocketFD;
}

int main(int argc, char* argv[]) {
	char ip[] = "127.0.0.1";
	UDPSocket mySock(ip, 2500);
	for (;;) {
		printf("here\n");
		printf("Message received %s\n", mySock.listen());
	}
}