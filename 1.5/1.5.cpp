// 1.5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

void BasicCompression(const char *input, char *output, int len)
{
	if (input == NULL || output == NULL)
		return;
	if (*input == 0)
		return;
	int count = 1, outputLen = 0, originalLen = 0;
	const char *h = input;
	++input;
	++originalLen;
	while (*input != 0)
	{
		if (*input != *(input - 1))
		{
			char buffer[256] = { 0 };
			_snprintf_s(buffer, 255, "%d", count);
			output[outputLen++] = *(input - 1);
			strcpy(output + outputLen, buffer);
			outputLen += strlen(buffer);
			count = 1;
		}
		else
		{
			++count;
		}
		++originalLen;
		++input;
	}

	// Last piece
	char buffer[256] = { 0 };
	_snprintf_s(buffer, 255, "%d", count);
	output[outputLen++] = *(input - 1);
	strcpy(output + outputLen, buffer);
	outputLen += strlen(buffer);
	if (originalLen <= outputLen)
		strcpy(output, h);

}

int _tmain(int argc, _TCHAR* argv[])
{
	char input[10] = { "abcdefghi" };
	char output[20] = { 0 };

	BasicCompression(input, output, 10);
	printf("%s", output);

	return 0;
}

