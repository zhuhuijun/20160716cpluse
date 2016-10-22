#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <errno.h>
#include <string.h>


int main(int arg,char *args[]){
	struct termios term;
	struct termios oldterm;
	if(tcgetattr(STDIN_FILENO,&term)==-1){
		printf("tcgetattr error：%s\n", strerror(errno));
		return -1;
	}
	oldterm=term;//保存系统原始的termios
	//通过调用可以得到当前控制台控制字符的功能
	term.c_cc[VERASE]='\b';//代表当前字符的功能键'\b'退格键的ACII
	//term.c_cc[VINTR];//给进程送一个SIGINT信号建
	if(tcsetattr(STDIN_FILENO,TCSANOW,&term)==-1){
		printf("tcsetattr error：%s\n", strerror(errno));
		return -1;
	}
	char buf[1024];
	memset(buf,0,sizeof(buf));
	read(STDIN_FILENO,buf,sizeof(buf));
	printf("%s\n",buf );
	//还原
	tcsetattr(STDIN_FILENO,TCSANOW,&oldterm);
	return EXIT_SUCCESS;
}