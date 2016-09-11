#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/epoll.h>
#include <netinet/in.h>
#include <arpa/inet.h>

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
		printf("recv %s\n",buf );
		send(st,buf,rc,0)
	}
	return rc;
}
