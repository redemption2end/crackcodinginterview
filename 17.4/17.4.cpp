// 17.4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
int mymax(int a, int b)
{
	int c = (a - b) >> 31;
	return a + c * (a - b);
}

int _tmain(int argc, _TCHAR* argv[])
{

	printf("max(%d, %d): %d\n", 3, 4, mymax(3, 4));
	printf("max(%d, %d): %d\n", -5, 10000, mymax(-5, 10000));
	return 0;
}

