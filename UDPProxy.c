#include "UDPProxy.h"
#include "UDPSocket.h"
#include <stdio.h>

UDPProxy::UDPProxy(char* srcIP, unsigned short port) {
    initialize(srcIP, port);
}

void UDPProxy::initialize(char* srcIP, unsigned short port) {
    mSocket = new UDPSocket(srcIP, port);
}


int main(int argc, char* argv[]) {
    printf("start\n");
    char ip[] = "127.0.0.1";
    UDPProxy test(ip, 5220);
}
