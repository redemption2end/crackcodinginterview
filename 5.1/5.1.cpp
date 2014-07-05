// 5.1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int Insert(int N, int M, int i, int j)
{
	M <<= i;

	N &= ~((1 << (j - i + 1) - 1) << i);

	return N |= M;
}

int _tmain(int argc, _TCHAR* argv[])
{

	int N = 51, M = 3;
	printf("N %d M %d\n", N, M);

	printf("%d\n", Insert(N, M, 3, 4));

	return 0;
}

