#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <pthread.h>
#define MAXBUF 131072

int main(int arg,char *args[])
{
	if(arg<3) return -1;
	int port=atoi(args[2]);
	int st=socket(AF_INET,SOCK_DGRAM,0);//初始化一个socket
	//广播的权利开放出来
	int on=0;
	//设置socket的高级属性
	if(setsockopt(st,SOL_SOCKET,SO_BROADCAST,&on,sizeof(on))==-1)
	{
		printf("setsockopt failed %s\n",strerror(errno) );
		return EXIT_FAILURE;
	}
	struct sockaddr_in addr;//定义一个ip的结构
	memset(&addr,0,sizeof(addr));
	addr.sin_family=AF_INET;//设置结构类型为Tcp/ip
	addr.sin_port=htons(port);//设置端口号htons:将short类型从本地字节类型转化为net字节类型
	addr.sin_addr.s_addr=inet_addr(args[1]);//转化为网络类型
	char buf[1024];
	char *p=malloc(MAXBUF);
	while(1)
	{
		memset(buf,0,sizeof(buf));
		read(STDIN_FILENO,buf,sizeof(buf));
		//int rc=sendto(st,buf,strlen(buf),0,(struct sockaddr *)&addr,sizeof(addr));
		int rc=sendto(st,p,MAXBUF,0,(struct sockaddr *)&addr,sizeof(addr));
		if(rc==-1)
		{
			printf("sendto failed %s\n",strerror(errno) );
			break;
		}else
		{
			printf("rc=%d\n",rc);
		}
	}
	close(st);
	return EXIT_SUCCESS;
}