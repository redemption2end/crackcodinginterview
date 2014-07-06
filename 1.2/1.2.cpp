// 1.2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

void reverse(char *str)
{
	if (str == NULL || *str == 0)
		return;

	char *end = str;
	while (*(end + 1) != 0) ++end;
	while (str < end) {
		char temp = *str;
		*str = *end;
		*end = temp;

		++str;
		--end;
	}

}


int _tmain(int argc, _TCHAR* argv[])
{
	char str[12] = { "hujingfei" };
	printf(str);
	reverse(str);
	printf(str);
	return 0;
}

