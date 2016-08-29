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
void sockaddr_toa(const struct sockaddr_in *addr,char *IPaddr)
{
	unsigned char *p=(unsigned char *)&(addr->sin_addr.s_addr);
	sprintf(IPaddr,"%u.%u.%u.%u",p[0],p[1],p[2],p[3]);
}
int main(int arg,char *args[])
{
	if(arg<2) return -1;
	int port=atoi(args[1]);
	int st=socket(AF_INET,SOCK_DGRAM,0);//初始化一个socket
	
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
	char s[1024];
	//socklen_t len=0;
	struct sockaddr_in client_addr;//client 的ip
	socklen_t len=sizeof(client_addr);
	char *p=malloc(MAXBUF);
	while(1)
	{
		//初始化客户端的地址
		memset(&client_addr,0,sizeof(client_addr));
		memset(s,0,sizeof(s));
		//int rf=recvfrom(st,s,sizeof(s),0,(struct sockaddr *)&client_addr,&len);
		int rf=recvfrom(st,p,MAXBUF,0,(struct sockaddr *)&client_addr,&len);
		if(rf==-1)
		{
			printf("recvfrom error%s\n", strerror(errno));
			break;
		}else
		{
			printf("rf=%d\n",rf );
			printf("%s recv is %s", inet_ntoa(client_addr.sin_addr),s);
		}
	}
	close(st);
	return EXIT_SUCCESS;
}