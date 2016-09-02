#include <stdio.h>

void main(int arg,char *args[])
{
	int a=atoi(args[1]);
	int b=atoi(args[2]);
	int c=a+b;
	printf("%d\n", c);
}