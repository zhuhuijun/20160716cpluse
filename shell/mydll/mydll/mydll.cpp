// mydll.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "stdafx.h"
__declspec(dllexport) int add(int a,int b)
{
	return a+b;
}
