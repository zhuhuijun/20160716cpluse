#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
int main(int arg,char *args[])
{
	if(arg<2)
	{
		return -1;
	}
	int port=atoi(args[1]);
	int st=socket(AF_INET,SOCK_STREAM,0);//初始化一个socket
	int on=1;
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
	char s[1024];
	int client_st=0;
	//socklen_t len=0;
	struct sockaddr_in client_addr;//client 的ip
	//void *p=&client_addr;
	int i;
	for(i=0;i<5;i++)
	{
		//初始化客户端的地址
		memset(&client_addr,0,sizeof(client_addr));
		//
		socklen_t len=sizeof(client_addr);
		//接受客户端的连接会阻塞线程
		//client_st=accept(st,p,&len);
		client_st=accept(st,(struct sockaddr *)&client_addr,&len);
		if(client_st==-1){
			printf("accept error %s\n",strerror(errno));
			return EXIT_FAILURE;
		}
		printf("accept ip:%s\n",inet_ntoa(client_addr.sin_addr) );
		while(1)
		{
			memset(s,0,sizeof(s));
			int rc=recv(client_st,s,sizeof(s),0);
			if(rc>0)
			{
				printf("recv is %s", s);
				memset(s,0,sizeof(s));
				read(STDIN_FILENO,s,sizeof(s));
				send(client_st,s,strlen(s),0);
			}
			else
			{
				if(rc==0)
				{
					printf("client closed\n");
				}
				else
				{
					printf("recv error %s\n",strerror(errno));
				}
				break;
			}

		}

		close(client_st);
	}
	close(st);
	return EXIT_SUCCESS;
}