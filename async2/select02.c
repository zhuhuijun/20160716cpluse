//select 可以当成sleep函数来使用精确到微秒
//只能处理1024个连接
//fd_set fd1; FD_ZERO(&fd1) int socket st; FD_SET(st);FD_CTL(st);

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
	maxfd=listen_st;
	fd_set allset;
	int client_st=-1;
	

}