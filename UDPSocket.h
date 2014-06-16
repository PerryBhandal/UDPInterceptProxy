class UDPSocket {
	public:
		UDPSocket(char* ip, unsigned short port);
		char* listen();
		void send(char* toSend, int length);
		~UDPSocket();

	protected:
		char* mBuffer;
		int* mSocketFD;
		struct sockaddr* getSockStruct(char* ip, unsigned short port);
		virtual void bindSocket(char* ip, unsigned short port);
};