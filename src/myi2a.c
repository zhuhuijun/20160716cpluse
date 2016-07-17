/*
 * myi2a.c
 *
 *  Created on: 2016-7-16
 *      Author: huijun
 */
#include <stdio.h>
int len(const char *str)
{
	int i = 0;
	while (str[i])
	{
		i++;
	}
	return i;
}
void strneg(char *str)//字符串加符号
{
	int i_len = len(str);
	int i = i_len - 1;
	for (; i >= 0; i++)
	{
		str[i + 1] = str[i];
	}
	str[0] = '-';
}
void reverse(char *str)
{
	int i_len = len(str);
	char tmp = 0;
	int i = 0;
	for (; i < (i_len / 2); i++)
	{
		tmp = str[i];
		str[i] = str[i_len - 1 - i];
		str[i_len - 1 - i] = tmp;
	}
}
const char *myi2a(int src)
{
	static char buf[128];
	int i = 0;
	for (; i < sizeof(buf); i++)
	{
		buf[i] = 0;
	}
	int neg = 0;
	if (src >= 0)
	{
		neg = 1;
	} else
	{
		src = 0 - src;
		neg = 0;
	}
	i = 0;
	while (1)
	{
		int n = src % 10;
		buf[i] = n + 0x30;
		i++;
		src /= 10;
		if (src == 0)
		{
			break;
		}
	}
	reverse(buf);
	if (neg == 0)
	{
		strneg(buf);
	}
	return buf;
}
void main(int arg, char *args[])
{
	int i = 100000;
	printf("%s\n", myi2a(i));
}

