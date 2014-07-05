// 9.6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
using namespace std;
void printAll(string input, int i, int l, int r, int n)
{
	if (i >= 2 * n)
	{
		if (l == r)
		{
			printf("%s \n", input.c_str());
		} 
		return;
	}

	if (r > l || l > n)
		return;

	input[i] = '(';
	printAll(input, i + 1, l + 1, r, n);

	input[i] = ')';
	printAll(input, i + 1, l, r + 1, n);
}

int _tmain(int argc, _TCHAR* argv[])
{
	string input(8, ' ');

	printf("input %s\n", input.c_str());

	printAll(input, 0, 0, 0, 4);

	return 0;
}

