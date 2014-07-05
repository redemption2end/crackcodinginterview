// 5.4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int swap(int input)
{
	int num = 1;
	for (int i = 0; i < 31; i++)
	{
		if (i % 2 == 0)
		{
			num <<= 1;
		}
		else
		{
			num <<= 1;
			num |= 1;
		}
	}

	int num1 = (num << 1) | 1;

	int evens = input & num1;
	int odds = input & num;
	
	return (odds >> 1) | (evens << 1);
}

int _tmain(int argc, _TCHAR* argv[])
{
	int N = 73;
	printf("%d \n", swap(N));

	return 0;
}

