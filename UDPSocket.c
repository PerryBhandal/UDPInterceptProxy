#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <string.h>
#include "UDPSocket.h"

UDPSocket::UDPSocket(char* ip, unsigned short port) {
	mBuffer = new char[1000];
	mSocketFD = new int;
	bindSocket(ip, port);
}

void UDPSocket::bindSocket(char* ip, unsigned short port) {
	struct sockaddr_in bindAddr;
	initSockAddrIn(&bindAddr, ip, port);

	//Create our socket
	*mSocketFD = socket(AF_INET, SOCK_DGRAM, 0);
    if (*mSocketFD < 0) 
    {
    	fprintf(stderr, "Error in socket creation.");
    	//TODO: Add exit here.
   	}

   	//Bind our socket
   	if (bind(*mSocketFD, (struct sockaddr *) &bindAddr, sizeof(bindAddr)) < 0) {
   		fprintf(stderr, "Error while binding.");
   		//TODO: Add exit
   	}
}

char* UDPSocket::getBufferPtr() {
	return mBuffer;
}

int UDPSocket::listen() {
	int n;
	socklen_t len;

	struct sockaddr_in cliAddr;
	bzero(&cliAddr, sizeof(cliAddr));

	len = sizeof(cliAddr);
	n = recvfrom(*mSocketFD, mBuffer, 1000, 0, (struct sockaddr*) &cliAddr, &len);
	return n;
}

void UDPSocket::initSockAddrIn(struct sockaddr_in* structPtr, char* ip, unsigned short port) {
	bzero(structPtr, sizeof(*structPtr));
	structPtr->sin_family = AF_INET;
	inet_pton(AF_INET, ip, &(structPtr->sin_addr));
	structPtr->sin_port = htons(port);
}

void UDPSocket::send(char* toSend, int length) {
	//sendto(*mSocket, toSend, length, 0, (struct sockaddr *) &cliAddr, sizeof(cliAddr));
}

UDPSocket::~UDPSocket() {
	delete mSocketFD;
	delete [] mBuffer;
}