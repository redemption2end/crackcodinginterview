// 7.4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int add(int a, int b)
{
	return a + b;
}

int negative(int a)
{
	int delta = a >= 0 ? -1 : 1;
	int crease = a >= 0 ? 1 : -1;
	int ret = 0;
	for (int i = 0; i != a; i = add(i, crease))
	{
		ret = add(ret, delta);
	}
	return ret;
}

int abs(int a)
{
	return a >= 0 ? a : negative(a);
}

int multiply(int a, int b)
{
	int oper1 = 0, oper2 = 0;
	if (a >= 0 || b >= 0)
	{
		oper1 = a >= 0 ? a : b;
		oper2 = oper1 == a ? b : a;
	}
	else
	{
		oper1 = negative(a);
		oper2 = negative(b);
	}

	int ret = 0;
	for (int i = 0; i != oper1; i = add(i, 1))
	{
		ret += oper2;
	}

	return ret;
}

int subtract(int a, int b)
{
	return add(a, negative(b));
}


int _tmain(int argc, _TCHAR* argv[])
{

	printf("abs(0) : %d\n", abs(0));
	printf("abs(1) : %d\n", abs(1));
	printf("abs(-1) : %d\n", abs(-1));

	printf("negative(0) : %d\n", negative(0));

	printf("negative(-1) : %d\n", negative(-1));

	printf("negative(10) : %d\n", negative(10));

	printf("multiply(0, 1): %d\n", multiply(0, 1));

	printf("multiply(10, 0): %d\n", multiply(10, 0));

	printf("multiply(10, -10): %d\n", multiply(10, -10));

	printf("multiply(-10, -10): %d\n", multiply(-10, -10));

	printf("multiply(-10, 10): %d\n", multiply(-10, 10));

	printf("multiply(8, 7): %d\n", multiply(8, 7));

	return 0;
}

