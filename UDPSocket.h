class UDPSocket {
	public:
		UDPSocket(char* ip, unsigned short port);
		char* listen();
		~UDPSocket();

	protected:
		char* mBuffer;
		int* mSocketFD;
		virtual void bindSocket(char* ip, unsigned short port);
};