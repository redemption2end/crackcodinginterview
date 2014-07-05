// 18.2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "time.h"
#include <stdlib.h>

void shuffle(int *cards, int length)
{
	for (int i = 0; i < length - 1; i++)
	{
		int idx = rand() % (length - i) + i;
		int temp = cards[idx];
		cards[idx] = cards[i];
		cards[i] = temp;
	}
}

void simulation1()
{
	int length = 52;
	int *cards = new int[length];
	for (int i = 0; i < length; i++)
	{
		cards[i] = i + 1;
	}

	shuffle(cards, length);

	for (int i = 0; i < length; i++)
	{
		printf("%d ", cards[i]);
	}
	printf("\n");
}
int _tmain(int argc, _TCHAR* argv[])
{
	srand(time(NULL));

	simulation1();

	simulation1();

	simulation1();

	simulation1();

	return 0;
}

