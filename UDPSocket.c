#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <string.h>
#include "UDPSocket.h"

UDPSocket::UDPSocket(char* ip, unsigned short port) {
	mCliAddr = mBindAddr = NULL;
	mBuffer = new char[1000];
	mSocketFD = new int;
	bindSocket(ip, port);
}

void UDPSocket::bindSocket(char* ip, unsigned short port) {

	//Create our socket
	*mSocketFD = socket(AF_INET, SOCK_DGRAM, 0);
    if (*mSocketFD < 0) 
    {
    	fprintf(stderr, "Error in socket creation.");
    	//TODO: Add exit here.
   	}

   	mBindAddr = getSockStruct(ip, port);
   	//Bind our socket
   	if (bind(*mSocketFD, (struct sockaddr *) mBindAddr, sizeof(mBindAddr)) < 0) {
   		fprintf(stderr, "Error while binding.");
   		//TODO: Add exit
   	}
}

int UDPSocket::listen() {
	int n;
	socklen_t len;

	len = sizeof(mCliAddr);
	n = recvfrom(*mSocketFD, mBuffer, 1000, 0, (struct sockaddr*) mCliAddr, &len);
	return n;
}

void UDPSocket::send(char* toSend, int length) {
	//sendto(*mSocket, toSend, length, 0, (struct sockaddr *) &cliAddr, sizeof(cliAddr));
}

struct sockaddr_in* UDPSocket::getSockStruct(char* ip, unsigned short port) {
	struct sockaddr_in* sockStruct = new struct sockaddr_in;
	bzero(sockStruct, sizeof(*sockStruct));
	sockStruct->sin_family = AF_INET;
	inet_pton(AF_INET, ip, &(sockStruct->sin_addr));
	return sockStruct;
}

UDPSocket::~UDPSocket() {
	if (mCliAddr != NULL)
		delete mCliAddr;

	if (mBindAddr != NULL)
		delete mBindAddr;

	delete mSocketFD;
	delete [] mBuffer;
}