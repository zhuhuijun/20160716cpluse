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
int char2i(char c)
{
	if ((c >= '0') && (c <= '9'))
	{
		return c - 0x30;
	}
	return 0;
}
int power10(int n)
{
	if (n == 0)
	{
		return 1;
	}
	int i = 1;
	int val = 10;
	for (; i < n; i++)
	{
		val *= 10;
	}
	return val;
}
int myatoi(const char *str)
{
	const char *p = NULL;
	int neg; //标志位
	if (str[0] == "-")
	{
		neg = 0;
		p = ++str;
	} else
	{
		neg = 1;
		p = str;
	}
	int i_len = len(p);
	int i_temp = i_len;
	int value = 0;
	int i = 0;
	for (; i < i_len; i++)
	{
		value += (power10(i_temp - 1) * char2i(p[i]));
		i_temp--;
	}
	if (neg == 0)
	{
		return 0 - value;
	} else
	{
		return value;
	}
}
int main(int arg, char *args[])
{
	const char *s = "100";
	printf("%d\n", myatoi(s));
	return 0;
}
