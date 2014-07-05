// 18.4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int count2s(int n)
{
	if (n <= 1){
		return 0;
	}

	int base = 10, cut = 1;
	int t = n, total = 0;
	while (t > 0)
	{
		int num = 0;
		int digit = t % base;

		if (digit <= 2)
		{
			if (digit == 2)
				num = (n / (cut * base) + 1) * (n % cut + 1);
			else
				num = (n / (cut * base)) * cut;
		}
		else
		{
			num = (n / (cut * base) + 1) * cut;
		}

		total += num;
		cut *= base;
		t /= base;
	}

	return total;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int n = 25;

	printf("number of 2 is %d\n", count2s(n));

	n = 30;

	printf("number of 2 is %d\n", count2s(n));

	n = 100;
	printf("number of 2 is %d\n", count2s(n));

	n = 101;
	printf("number of 2 is %d\n", count2s(n));

	n = 102;
	printf("number of 2 is %d\n", count2s(n));

	n = 2;
	printf("number of 2 is %d\n", count2s(n));
	return 0;
}

