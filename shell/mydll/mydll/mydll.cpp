// mydll.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
__declspec(dllexport) int add(int a,int b)
{
	return a+b;
}
