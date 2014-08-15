class UDPSocket;

class UDPProxy {
    public:
        UDPProxy(char* srcIP, unsigned short port);
        void startProxy();

    private:
        UDPSocket* mSocket;
        void initialize(char* srcIP, unsigned short port);
};
