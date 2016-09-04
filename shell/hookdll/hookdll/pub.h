#pragma once
#ifdef  __CPLUSPLUS
extern "C" {
#endif

	int init_socket();
	void close_socket(SOCKET st);
	SOCKET create_send_socket();
	int send_work(SOCKET st,const char *hostname,int port,const char *s);

#ifdef  __CPLUSPLUS
}
#endif