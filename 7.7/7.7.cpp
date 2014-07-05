// 7.7.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
int generate(int k)
{
	int *buf = new int[k + 1];
	buf[0] = 1;
	int idx3 = 0, idx5 = 0, idx7 = 0;
	for (int i = 1; i <= k; i++)
	{
		int v3 = buf[idx3] * 3;
		int v5 = buf[idx5] * 5;
		int v7 = buf[idx7] * 7;

		int m = v3 > v5 ? v5 : v3;
		m = m > v7 ? v7 : m;

		if (m == v3)
		{
			idx3++;
		}
		if (m == v5)
		{
			idx5++;
		}
		if (m == v7)
		{
			idx7++;
		}

		buf[i] = m;
	}
	int ret = buf[k];
	delete[] buf;
	return ret;
}



int _tmain(int argc, _TCHAR* argv[])
{

	for (int i = 1; i <= 10; i++)
	{
		printf("%d ", generate(i));
	}
	return 0;
}

