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
	if(arg<3)
	{
		return -1;
	}
	int port=atoi(args[2]);
	int st=socket(AF_INET,SOCK_STREAM,0);//初始化一个socket
	struct sockaddr_in addr;//定义一个ip的结构
	memset(&addr,0,sizeof(addr));
	addr.sin_family=AF_INET;//设置结构类型为Tcp/ip
	addr.sin_port=htons(port);//设置端口号htons:将short类型从本地字节类型转化为net字节类型
	addr.sin_addr.s_addr=inet_addr(args[1]);
	if(connect(st,(struct sockaddr *)&addr,sizeof(addr))==-1)
	{
		printf("connect error %s\n",strerror(errno));
		return EXIT_FAILURE;
	}
	char s[1024];
	while(1)
	{
		memset(s,0,sizeof(s));
		read(STDIN_FILENO,s,sizeof(s));
		//strcpy(s,"hello,world");
		if(send(st,s,strlen(s),0)==-1)
		{
			printf("connect error %s\n",strerror(errno));
			return EXIT_FAILURE;
		}
		memset(s,0,sizeof(s));
		if(recv(st,s,sizeof(s),0)>0)
		{
			printf("client receive %s",s);
		}else{
		//接受失败就退出
			break;
		}
	
		
	}
	close(st);
	return EXIT_SUCCESS;
}