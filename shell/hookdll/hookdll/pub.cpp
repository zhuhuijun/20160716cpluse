#include "stdafx.h"
#include <stdio.h>
#include "pub.h"
#pragma comment(lib,"Ws2_32.lib")
int init_socket()
{
	WORD wVersionRequested;
	WSADATA wsaData;
	int err;
	wVersionRequested=MAKEWORD(1,1);
	err=WSAStartup(wVersionRequested,&wsaData);
	if(err!=0)
	{
		return -1;
	}
	if(LOBYTE(wsaData.wVersion)!=1||HIBYTE(wsaData.wVersion)!=1)
	{
		WSACleanup();
		return -1;
	}
	return 0;
}
void close_socket(SOCKET st)
{
	closesocket(st);
	WSACleanup();
}
//创建socket
SOCKET create_send_socket()
{
	SOCKET st=socket(AF_INET,SOCK_DGRAM,0);
	if(st==0)
		return 0;
	return st;
}
//send
int send_work(SOCKET st,const char *hostname,int port,const char *s)
{
	struct sockaddr_in addr;//定义一个ip的结构
	memset(&addr,0,sizeof(addr));
	addr.sin_family=AF_INET;//设置结构类型为Tcp/ip
	addr.sin_port=htons(port);//设置端口号htons:将short类型从本地字节类型转化为net字节类型
	addr.sin_addr.s_addr=inet_addr(hostname);//转化为网络类型
	size_t rc=sendto(st,s,strlen(s),0.
		(struct sockaddr *)&addr,sizeof(addr));
	return rc;

}