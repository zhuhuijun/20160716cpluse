int SocketCreate(SOCKET &sock,const char *IPAddr,unsigned short port)
{
	unsigned short wVersion;
	WSADATA wsaData;
	wVersion=MAKEWORD(1,1);
	int iRes=WSAStartup(wVersion,&wsaData);
	if(iRes!=0)
		return iRes;
	//创建原始的socket
	sock=socket(AF_INET,SOCK_RAW,IPPROTO_IP);
	if(sock==INVALID_SOCKET)
		return WSAGetLastError();
}