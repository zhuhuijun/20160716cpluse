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
SOCKET create_recv_socket(int port)
{
	SOCKET st=socket(AF_INET,SOCK_DGRAM,0);
	if(st==0)
		return 0;

	struct sockaddr_in addr;//定义一个ip的结构
	memset(&addr,0,sizeof(addr));
	addr.sin_family=AF_INET;//设置结构类型为Tcp/ip
	addr.sin_port=htons(port);//设置端口号htons:将short类型从本地字节类型转化为net字节类型
	addr.sin_addr.s_addr=htonl(INADDR_ANY);//转化为网络类型

	if(bind(st,(struct sockaddr *)&addr,sizeof(addr))==-1)
	{
		printf("bind failed %s\n",strerror(errno) );
		return 0;
	}
	return st;
}
SOCKET create_send_socket()
{
	if(init_socket()==-1)
		return 0;
	SOCKET st=socket(AF_INET,SOCK_DGRAM,0);//建立连接
	if(st==0)
		return 0;
	return st;//udp socket建立成功返回socket的描述
}
int send_work(const char *hostname,int port,const char *filename)
{
	SOCKET st_send=create_send_socket();//建立发送的UDP SOCKET
	SOCKET st_recv=create_recv_socket(port+1);//建立接收数据的UDP Socket
	if(st_send==0) return 0;//建立失败，函数返回
	if(st_recv==0) return 0;//建立失败，函数返回
	FILE *fd=fopen(filename,"rb");
	if(fd==NULL)
	{
		printf("open %s failed %s\n",filename,strerror(errno) );
	}
	char *buf=malloc(BUFSIZE);//申请一个缓冲区存放接收到的文件内容
	memset(buf,0,BUFSIZE);
	getfilename(filename,buf);//从完整路径中解析出文件名称
	struct sockaddr_in addr;
	memset(&addr,0,sizeof(addr));
	addr.sin_family=AF_INET;
	addr.sin_port=htons(port);//指定port为要连接的端口号
	addr.sin_addr.s_addr=inet_addr(hostname);

	size_t rc=sendto(st_send,buf,strlen(buf),0,
		(struct sockaddr *) &addr,sizeof(addr));//传送文件的名称
	if(rc<=0)
	{
		printf("send failed1 %s\n",strerror(errno) );
	}
	else//发送成功
	{
		struct sockaddr_in client_addr;
		#ifdef WIN
		int len=0;
		#else
		unsigned int len=0;
		#endif
		len =sizeof(client_addr);
		memset(&client_addr,0,sizeof(client_addr));
		memset(buf,0,BUFSIZE);
		if(recvfrom(st_recv,buf,BUFSIZE,0,
			(struct sockaddr *)&client_addr,&len)<=0)
		{
			if(strncmp(buf,"OK",2)==0)
			{
				while(1)
				{
					memset(buf,0,BUFSIZE);
					rc=fread(buf,1,BUFSIZE,fd);
					if(rc<=0)
						{break;}
					else
					{
						rc=sendto(st_send,buf,rc,0,(struct sockaddr *)&addr,
							sizeof(addr));//将读到的文件数据发送到server
						if(rc<=0)
						{
							printf("send failed%s\n",strerror(errno) );
							break;
						}
					}
				}
			}
			memset(buf,0,BUFSIZE);
			rc=sendto(st_send,buf,128,0,(struct sockaddr *)&addr,
				sizeof(addr));
			//连续发送128个0表示发送结束
		}
	}
	fclose(fd);
	free(buf);
#ifdef WIN
	closescoket(st_send);
	WSACleanup();
#else
	close(st_send);
	close(st_recv);
#endif
	return 1;
}
//接受的
int recv_work (int port)
{
	SOCKET st_send=create_send_socket();
	SOCKET st_recv=create_recv_socket(port);
	if(st_send==0)
		return 0;
	if(st_recv==0) return 0;
	char *buf=malloc(BUFSIZE);
	FILE *fd=NULL;

		#ifdef WIN
	int len=0;
		#else
	unsigned int len=0;
		#endif

	struct sockaddr_in client_addr;
	len=sizeof(client_addr);
	memset(&client_addr,0,sizeof(client_addr));
	memset(buf,0,BUFSIZE);
	size_t rc=recvfrom(st_recv,buf,BUFSIZE,0,
		(struct sockaddr *)&client_addr,&len);
	if(rc<=0)
	{
		printf("recv failed %s\n",strerror(errno));
	}else
	{
		printf("receving %s \n",buf );
		fd=fopen(buf,"wb");
		if(fd==NULL)
		{
			printf("open %s failed %s\n",buf,strerror(errno) );
		}else{
			client_addr.sin_port=htons(port+1);
			memset(buf,0,sizeof(BUFSIZE));
			strcpy(buf,"OK");

			rc=sendto(st_send,buf,strlen(buf),0,
				(struct sockaddr *)&client_addr,sizeof(client_addr));
			if(rc<=0)
			{
				printf("send failed %s\n",strerror(errno) );
			}
			while(1)
			{
				memset(buf,0,BUFSIZE);
				//循环接受client的数据
				rc=recvfrom(st_recv,buf,BUFSIZE,0,
					(struct sockaddr *)&client_addr,&len);
				char tmp[128];
				memset(tmp,0,sizeof(tmp));
				if(memcmp(buf,tmp,sizeof(tmp))==0)
					break;
				if(rc<=0)
				{
					printf("recv failed%s\n",strerror(errno) );
					break;
				}else
				{
					fwrite(buf,1,rc,fd);
				}
			}
		}
	}
	if(fd) fclose(fd);
	free(buf);
	#ifdef WIN
	closescoket(st_send);
	closescoket(st_recv);
	WSACleanup();
	#else
	close(st_send);
	close(st_recv);

	#endif
	return 1;
}