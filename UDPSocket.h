class UDPSocket {
    public:
        UDPSocket(char* ip, unsigned short port);
        int listen();
        void send(char* toSend, int length);
        char* getBufferPtr();
        ~UDPSocket();

    protected:
        void initSockAddrIn(struct sockaddr_in* structPtr, char* ip, unsigned short port);
        char* mBuffer;
        int* mSocketFD;
        virtual void bindSocket(char* ip, unsigned short port);
};
