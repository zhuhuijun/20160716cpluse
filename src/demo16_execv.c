#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(int argc, char const *argv[])
{
	char *args[]={"/bin/ls","-l",NULL};
	execve("/bin/ls",args,NULL);
	return 0;
}