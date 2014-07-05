#include "stdafx.h"
#include "TripleStack.h"


TripleStack::TripleStack(int n)
{
	this->n = n;
	this->arry = new int [3 * n];

	top[0] = top[1] = top[2] = -1;
}


TripleStack::~TripleStack()
{
}

void TripleStack::push(int stackIndex, int value)
{
	if (stackIndex < 0 || stackIndex >= 3)
		return;
	if (top[stackIndex] >= n)
		return;
	int idx = stackIndex * n + (++top[stackIndex]);
	arry[idx] = value;
}

int TripleStack::pop(int stackIndex)
{
	if (top[stackIndex] >= 0)
	{
		int idx = stackIndex * n + (top[stackIndex]--);
		return arry[idx];
	}
	return -1;
}

void TripleStack::show()
{
	for (int i = 0; i < 3; i++)
	{
		printf("\nStack %d\n", i);
		for (int j = 0; j <= top[i]; j++)
		{
			printf("%d ", arry[i * n + j]);
		}

	}
}