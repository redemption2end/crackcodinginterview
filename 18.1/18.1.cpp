// 18.1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int add(int a, int b)
{
	while (b != 0)
	{
		int carry = (a & b) << 1;
		a = a ^ b;
		b = carry;
	}

	return a;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int a = 1, b = 2;
	printf("%d + %d = %d\n", a, b, add(a, b));

	a = 10, b = 1000;
	printf("%d + %d = %d\n", a, b, add(a, b));

	a = -10, b = 1000;
	printf("%d + %d = %d\n", a, b, add(a, b));

	a = -10, b = -1000;
	printf("%d + %d = %d\n", a, b, add(a, b));
	return 0;
}

