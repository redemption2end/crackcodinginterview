// 1.3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

bool IsPermutation(const char *s, const char *t)
{
	if (s == NULL || t == NULL)
		return false;
	int occurs[256] = { 0 };
	int len = 0;
	while (*s != 0)
	{
		++len;
		occurs[*s++]++;
	}

	while (*t != 0)
	{
		--occurs[*t];
		--len;
		if (len < 0)
			return false;
		if (occurs[*t] < 0)
			return false;
		++t;
	}
	return len == 0;
}


int _tmain(int argc, _TCHAR* argv[])
{
	printf(IsPermutation("hujjng", "ujjngx") ? "yes": "no");
	return 0;
}

