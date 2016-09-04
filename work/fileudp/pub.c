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

int send_work(const char *hostname,int port,const char *filename)
{
	SOCKET st_send=create_send_socket();//建立发送的UDP SOCKET
	SOCKET st_recv=create_recv_socket(port+1);//建立接收数据的UDP Socket
	if(st_send==0) return 0;//建立失败，函数返回
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
	close(fd);
	free(buf);
#ifdef WIN
	closescoket(st);
	WSACleanup();
#else
	close(st);
#endif
	return 1;
}
