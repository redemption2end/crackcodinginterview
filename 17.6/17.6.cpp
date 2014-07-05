// 17.6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

void smallestSeq(int *arr, int len, int &m, int &n)
{
	n = m = 0;
	int i = 0;
	while ((i + 1) < len && arr[i] <= arr[i + 1]) ++i;

	if ((i + 1) == len)
		return;

	int j = len - 1;
	while ((j - 1) >= 0 && arr[j] >= arr[j - 1]) --j;
	if (j < 1)
		return;

	int min = arr[i], max = arr[i];
	for (; i <= j; i++)
	{
		if (arr[i] < min)
			min = arr[i];
		if (arr[i] > max)
			max = arr[i];
	}

	i = 0;
	while (arr[i] <= min) i++;
	m = i;
	i = len - 1;
	while (arr[i] >= max) i--;
	n = i;
}


int _tmain(int argc, _TCHAR* argv[])
{
	int arr[] = { 1, 2, 4, 7, 10, 11, 7, 12, 1, 7, 16, 18, 19 };
	int n, m;
	smallestSeq(arr, sizeof(arr) / sizeof(int), m, n);
	printf("%d %d\n", m, n);


	return 0;
}

