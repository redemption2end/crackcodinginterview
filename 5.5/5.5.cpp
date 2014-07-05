// 5.5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


bool getBit(int *arr, int i, int j)
{
	return (arr[i] & (1 << (j))) != 0;
}

void findMissing(int *arr, int n)
{
	int z[32] = { 0 }, o[32] = { 0 };
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 32; j++)
		{
			if (getBit(arr, i, j) == true)
			{
				o[j] ++;
			}
			else
			{
				z[j] ++;
			}
		}
	}

	int base = 1, c = 0;
	for (int j = 0; j < 32 && j < 4; j++)
	{
		bool isOne = getBit(arr, 1, j);
		int numberOf1Or0 = c + 1;

		if (isOne)
		{
			if ((z[j] - base) > (o[j] - numberOf1Or0))
			{
				printf("1");
			}
			else {
				printf("0");
			}
		}
		else
		{
			if (o[j] > (z[j] - numberOf1Or0))
			{
				printf("0");
			}
			else
			{
				printf("1");
			}
		}

		c = (isOne ? 1 : 0) * base + c;
		base <<= 1;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	int arr[9] = {0, 9, 7, 2, 1, 4, 8, 6, 3 };

	findMissing(arr, 9);

	return 0;
}

