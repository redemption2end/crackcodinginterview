// 17.3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int trailingZeros(long n)
{
	int num = 0;
	while (n >= 5)
	{
		num += (n / 5);
		n /= 5;
	}

	return num;
}

int _tmain(int argc, _TCHAR* argv[])
{
	long factorial = 1;
	for (int i = 1; i <= 100; i++)
	{
		printf("%d\t%d\n", i, trailingZeros(i));
	}

	return 0;
}

