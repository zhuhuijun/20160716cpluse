// hookdlltest.cpp : ����Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "hookdlltest.h"
#include "hookdll.h"
//#pragma comment(lib,"hookdll.lib")
int APIENTRY _tWinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPTSTR    lpCmdLine,
                     int       nCmdShow)
{
	InstallLanuchEv();
	::Sleep(300000);
	UnInstallLanuchEv();
	return 0;
}