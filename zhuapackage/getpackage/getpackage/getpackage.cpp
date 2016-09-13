// getpackage.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>

void _tmain(int argc, _TCHAR* argv[])
{
	if(argc<3)
	{
		printf("usage:%s IPAddress port [byte]\n",argv[0]);
		system("pause");
	}
	printf("author:zhuhj by 2016-09-13\n");
	SOCKET sock;
	int iPort=atoi(argv[2]);
	int iRes=SocketCreate(sock,argv[1],(unsigned short) iPort);
	if(iRes!=0)
	{

	}
	system("pause");
}

