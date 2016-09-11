#ifdef WIN
#include <WinSock2.h>
#else
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <errno.h>
#include <string.h>
#define SOCKET int
#endif

#include <stdio.h>
#include "pub.h"

#define BUFSIZE 262144 //256K
void getfilename(const char *filename,char *name)
{
	int len=strlen(filename);
	int i;
	for(i=(len-1);i>=0;i--)
	{
		if((filename[i]=='\\')||(filename[1]=='/'))
		{
			break;
		}
	}
	strcpy(name,&filename[i+1]);
	return ;
}
//初始化socket
SOCKET init_socket()
{
#ifdef WIN
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
#endif
	return 0;
}
SOCKET socket_create(int port)
{
	if(init_socket()==-1)
		return 0;
	SOCKET st=socket(AF_INET,SOCK_STREAM,0);
	if(st==0)
	{
		return 0;
	}
#ifdef WIN
	const char on=0;
#else
	int on=0;
#endif
	if(setsockopt(st,SOL_SOCKET,SO_REUSEADDR,&on,sizeof(on))==-1)
	{
		printf("setsockopt failed %s\n",strerror(errno) );
		return EXIT_FAILURE;
	}
	struct sockaddr_in addr;//定义一个ip的结构
	memset(&addr,0,sizeof(addr));
	addr.sin_family=AF_INET;//设置结构类型为Tcp/ip
	addr.sin_port=htons(port);//设置端口号htons:将short类型从本地字节类型转化为net字节类型
	addr.sin_addr.s_addr=htonl(INADDR_ANY);//转化为网络类型
	if(bind(st,(struct sockaddr *)&addr,sizeof(addr))==-1)
	{
		printf("bind error %s\n",strerror(errno));
		return EXIT_FAILURE;
	}
	if(listen(st,20)==-1){//同时有多少连接过来
		printf("listen error %s\n",strerror(errno));
		return EXIT_FAILURE;
	}	
	printf("listen %d success\n",port );
	return st;
}
SOCKET socket_accept(SOCKET listen_st)
{

	struct sockaddr_in client_addr;
	#ifdef WIN
	int len=0;
	#else
	unsigned int len=1;
	#endif

	len=sizeof(client_addr);
	memset(&client_addr,0,sizeof(client_addr));
	SOCKET client_st=accept(listen_st,(struct sockaddr *)&client_addr,
		&len);
	if(client_st==-1)
	{
		printf("accept failed %s\n",strerror(errno) );
		return 0;
	}else
	{
		printf("accept by %s\n",inet_ntoa(client_addr.sin_addr) );
		return client_st;
	}
}
SOCKET socket_connect(const char *hostname,int port)
{
	if(init_socket()==-1)
		return 0;
	SOCKET st=socket(AF_INET,SOCK_STREAM,0);
	if(st==0)return 0;
	struct  sockaddr_in addr;
	memset(&addr,0,sizeof(addr));
	addr.sin_family=AF_INET;//设置结构类型为Tcp/ip
	addr.sin_port=htons(port);//设置端口号htons:将short类型从本地字节类型转化为net字节类型
	addr.sin_addr.s_addr=inet_addr(hostname);
	if(connect(st,(struct sockaddr *)&addr,sizeof(addr))==-1)
	{
		printf("connect to %s:%d  error %s\n",
			hostname,port,strerror(errno));
		return 0;
	}else
	{
		return st;
	}
}
int send_work(const char *hostname,int port,const char *filename)
{
	SOCKET st=socket_connect(hostname,port);
	if(st==0) return 0;
	FILE *fd=fopen(filename,"rb");
	if(fd==NULL)
	{
		printf("open %s failed %s\n",filename,strerror(errno) );
	}
	char *buf=malloc(BUFSIZE);
	memset(buf,0,BUFSIZE);
	getfilename(filename,buf);//从完整路径中解析出文件名称
	size_t rc=send(st,buf,strlen(buf),0);//传送文件的名称
	if(rc<=0)
	{
		if(rc<0)
			printf("send failed %s\n",strerror(errno) );
		else
			printf("socket is disconnect \n");
	}
	else
	{
		memset(buf,0,BUFSIZE);
		if(recv(st,buf,BUFSIZE,0)<=0)
		{
			if(rc<0)
				printf("recv failed %s\n",strerror(errno) );
			else
				printf("socket disconnect \n");
		}else
		{
			if(strncmp(buf,"OK",2)==0)//收到文件名称后就发送文件内容
			{
				while(1)
				{
					memset(buf,0,BUFSIZE);
					rc=fread(buf,1,BUFSIZE,fd);
					if(rc<=0)
					{
						if(rc<0)
							printf("fread failed %s\n",strerror(errno) );
						break;
					}else
					{
						rc=send(st,buf,rc,0);
						if(rc<=0)
						{
							if(rc<0)
								printf("send failed %s\n",strerror(errno) );
							else
								printf("socket disconnect %s\n",strerror(errno) );
							break;
						}
					}
				}
			}
		}
	}
	fclose(fd);
	free(buf);
#ifdef WIN
	closescoket(st);
	WSACleanup();
#else
	close(st);
#endif
	return 1;
}

//接受
int recv_work(int port)
{
	SOCKET listen_st=socket_create(port);//建立server端socket 
	if(listen_st==0)
		return 0;
	SOCKET st=socket_accept(listen_st);
	if(st==0)
		return 0;

	char *buf=malloc(BUFSIZE);
	FILE *fd=NULL;
	memset(buf,0,BUFSIZE);
	size_t rc=recv(st,buf,BUFSIZE,0);
	if(rc<=0)
	{
		if(rc<0)
			printf("recv failed %s\n",strerror(errno) );
		else
			printf("socket disconnect\n");
	}else
	{
		printf("recving %s\n",buf );
		fd=fopen(buf,"wb");
		if(fd==NULL)
		{
			printf("open %s failed %s\n",buf,strerror(errno) );
		}else
		{
			memset(buf,0,BUFSIZE);
			strcpy(buf,"OK");
			rc=send(st,buf,strlen(buf),0);
			if(rc<=0)
			{
				if(rc<0)
					printf("send failed %s\n",strerror(errno) );
				else
					printf("socket disconnect\n");
			}
			while(1)
			{
				memset(buf,0,BUFSIZE);
				rc=recv(st,buf,BUFSIZE,0);
				if(rc<=0)
				{
					if(rc<0)
						printf("recv failed %s\n", strerror(errno));
					else
						printf("socket disconnect\n");
					break;
				}else
				{
					fwrite(buf,1,rc,fd);
				}
			}
		}
	}
	if(fd)
		fclose(fd);
	free(buf);
	#ifdef WIN
	closescoket();
	closescoket(listen_st);
	WSACleanup();
	#else
	close(st);
	close(listen_st);
	#endif
	return 1;
}