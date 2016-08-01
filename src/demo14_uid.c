#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <pwd.h>

int main(int arg,char *args[])
{
	char *login=getlogin();
	struct passwd *ps=getpwname(login);
	printf("user name =%s\n", ps->pw_name);
	printf("uid = %s\n",ps->pw_uid );
	printf("home =%s\n",ps->pw_dir );
}