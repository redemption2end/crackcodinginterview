// 5.3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int nextSmallest(int n)
{
	int tmp = n;
	int exp1 = -1, exp0 = -1, idx = 0;
	while (tmp > 0)
	{
		if (tmp % 2 == 1 && exp1 == -1)
		{
			exp1 = idx;
		}

		if (tmp % 2 == 0 && exp1 != -1)
		{
			exp0 = idx;
		}

		++idx;
		tmp /= 2;
	}
	n |= (1 << (exp0));

	int numberOf1sLeft = exp0 - exp1 - 1;

	n |= ((1 << (numberOf1sLeft)) - 1);

	n &= ~(((1 << (exp0 - numberOf1sLeft)) - 1) << numberOf1sLeft);
	return n;
}

int _tmain(int argc, _TCHAR* argv[])
{

	int n = 20;
	printf("%d \n", nextSmallest(n));

	return 0;
}

