// 1.4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace std;

void EscapeSpace(char *str)
{
	if (str == NULL || *str == 0)
		return;

	char *temp = str;
	int numberOfSpace = 0, len = 0;
	while (*temp != 0)
	{
		if (*temp++ == ' ')
			++numberOfSpace;
		++len;
	}

	++len; // Include the NULL identifier
	int newLen = len + 2 * numberOfSpace;

	while (len >= 1)
	{
		if (str[len - 1] != ' ')
		{
			str[newLen - 1] = str[len - 1];
			if (str[newLen - 1] == 0)
			{
				printf("Last NULL character");
			}
			--newLen;
		}
		else {
			str[newLen - 1] = '0';
			str[newLen - 2] = '2';
			str[newLen - 3] = '%';
			newLen -= 3;
		}
		--len;
	}

	//printf(str);
}



int _tmain(int argc, _TCHAR* argv[])
{
	char input[100] = { "hu jing fei and yang yu yuan" };
	//printf(strlen(input));
	printf(input);
	EscapeSpace(input);
	printf("%s", input);
	return 0;
}

