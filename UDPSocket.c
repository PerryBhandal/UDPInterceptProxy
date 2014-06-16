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

	//Create our socket
	*mSocketFD = socket(AF_INET, SOCK_DGRAM, 0);
    if (*mSocketFD < 0) 
    {
    	fprintf(stderr, "Error in socket creation.");
    	//TODO: Add exit here.
   	}

   	//Assemble our binding data
   	bindAddr.sin_family = AF_INET;
   	
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

void UDPSocket::send(char* toSend, int length) {
	//sendto(*mSocket, toSend, length, 0, (struct sockaddr *) &cliAddr, sizeof(cliAddr));
}

struct sockaddr_in* getSockStruct(char* ip, unsigned short port) {
	struct sockaddr_in* sockStruct = new struct sockaddr_in;
	bzero(sockStruct, sizeof(*sockStruct));
	sockStruct->sin_family = AF_INET;
	inet_pton(AF_INET, ip, &(sockStruct->sin_addr));
	return sockStruct;
}

UDPSocket::~UDPSocket() {
	delete mSocketFD;
	delete [] mBuffer;
}