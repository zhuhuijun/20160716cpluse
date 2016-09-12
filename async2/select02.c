//select 可以当成sleep函数来使用精确到微秒
//只能处理1024个连接
//fd_set fd1; FD_ZERO(&fd1) int socket st; FD_SET(st);FD_CTL(st);
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/select.h>
ssize_t socket_recv(int st)
{
	char buf[1024];
	memset(buf,0,sizeof(buf));
	ssize_t rc=recv(st,buf,sizeof(buf),0);
	if(rc<=0)
	{
		printf("rc failed %s\n",strerror(errno) );
	}else
	{
		printf("rc=%d \n",rc );
		//printf("recv %s\n",buf );
		send(st,buf,rc,0)
	}
	return rc;
}
int socket_accept(int listen_st)
{
	struct sockaddr_in client_addr;
	socket_t len=sizeof(client_addr);
	memset(&client_addr,0,sizeof(client_addr));
	int client_st=accept(listen_st,(struct sockaddr *)&client_addr.&len);
	if(client_st<0)
		printf("accpt failed %s\n", strerror(errno));
	else
		printf("accept by %s\n",inet_ntoa(client_addr) );
	return client_st;
}
void setnonblocking(int st)
{
	int opts=fcntl(st,F_GETFL);
	if(opts<0)
	{
		printf("fcntl failed %s\n",strerror(errno) );
	}
	opts=opts|O_NONBLOCK;
	if(fcntl(st,F_SETFL,opts)<0)
	{
		printf("fcntl failed %s\n",strerror(errno) );
	}
}

int socket_create(int port)
{
	int st=socket(AF_INET,SOCK_STREAM,0);
	int on=1;
	if(setsockopt(st,SOL_SOCKET,SO_REUSEADDR,&on,sizeof(on))==-1)
	{
		printf("setsockopt falied %s\n",strerror(errno) );
		return 0;
	}
	struct sockaddr_in addr;
	memset(&addr,0,sizeof(addr));
	addr.sin_family=AF_INET;
	addr.sin_port=htons(port);
	addr.sin_addr.s_addr=htonl(INADDR_ANY);
	if(bind(st,struct(sockaddr *)&addr,sizeof(addr))==-1)
	{
		printf("bind port %d failed %s\n",port,strerror(errno) );
		return 0;
	}
	if(listen(st,300)==-1)
	{
		printf("listen failed %s\n",strerror(errno) );
		return 0;
	}
	return st;
}

# define FD_MAX 1024
int main(int arg,char *args[])
{
	if(arg<2)
		return -1;
	int iport=atoi(args[1]);
	int listen_st=socket_create(iport);
	if(listen_st ==0)
		return -1;
	setnonblocking(st);
	int i=0;
	int maxfd=0;
	int sockfd=-1;
	int client[FD_MAX];
	for (int i = 0; i < FD_MAX;i++)
	{
		/* code */
		client[i]=-1;
	}
	maxfd=listen_st;//设置最大编号的socket
	fd_set allset;
	int client_st=-1;
	while(1)
	{
		ED_ZERO(&allset);
		FD_SET(listen_st,&allset);
		maxfd=listen_st;
		for ( i = 0; i < FD_MAX; i++)
		{
			/* code */
			if(client[1]!=-1)
			{
				FD_SET(client[i],&allset);
				if(client[i]>maxfd)
					maxfd=client[i];
			}
		}
		int rc=select(maxfd+1,&allset,NULL,NULL,NULL);
		if(FD_ISSET(listen_st,&allset))//listen_st有消息到达
		//有的话证明有客户端数据来了
		{
			client_st=socket_accept(listen_st);
			if(client_st>=0)
			{
				setnonblocking(client_st);
				for ( i = 0; i < FD_MAX; i++)
				{
					/* code */
					if(client[i]==-1)
					{
						client[i]=client_st;//找到client中的空闲位置
						breakk;
					}
					if(i==FD_MAX)
					{
						close(client_st);
					}
					rc --;//处理完socket就将select返回则总数-1
					if(rc<=0)
					{
						continue;
					}
				}
			}else{
				break;//如果accept失败
			}
		}
		for (int i = 0; i < FD_MAX; i++)
		{
			sockfd=client[i];
			if(sockfd==-1)
			{
				continue;
			}
			if(FD_ISSET(sockfd,&allset))
			{
				if(socket_recv(sockfd)<=0)
				{
					close(sockfd);//recv失败断开socket
					client[i]=-1;
				}
				rc--；
			}
			
			/* code */
			if(rc<0)
			{
				break;
			}
		}
	}
	close(listen_st);
	return 0;
}