// 9.8.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int numberOf(int n)
{
	int *buf = new int[n + 1];
	buf[0] = 1;

	for (int i = 1; i <= n; i++)
	{
		if (i < 5)
		{
			buf[i] = buf[i - 1];
		}
		else if (i < 10)
		{
			buf[i] = buf[i - 1] + buf[i - 5];
		}
		else if (i < 25)
		{
			buf[i] = buf[i - 1] + buf[i - 5] + buf[i - 10];
		}
		else
		{
			buf[i] = buf[i - 1] + buf[i - 5] + buf[i - 10] + buf[i - 25];
		}
	}

	return buf[n];
}

int _tmain(int argc, _TCHAR* argv[])
{
	for (int i = 1; i < 51; i++)
	{
		printf("%d %d\n", i, numberOf(i));
	}

	return 0;
}

