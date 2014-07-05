#include "stdafx.h"
#include "TripleStack1.h"


TripleStack1::TripleStack1(int n)
{
	this->n = n;
	this->idx = new int[this->n];
	this->value = new int[this->n];

	current = 0;

	top[0] = top[1] = top[2] = -1;
}


TripleStack1::~TripleStack1()
{
}

void TripleStack1::push(int stackIndex, int v)
{
	if (current >= n)
		return;

	value[current] = v;

	idx[current] = top[stackIndex];
	top[stackIndex] = current;

	current++;
}

int TripleStack1::pop(int stackIndex)
{
	int x = top[stackIndex];
	top[stackIndex] = idx[x];
	return value[x];
}

void TripleStack1::show()
{
	for (int i = 0; i < 3; i++)
	{
		printf("\n Stack %d \n", i);

		int index = top[i];
		while (index != -1)
		{
			printf("idx: %d value: %d \t", index, value[index]);

			index = idx[index];
		}
	}
}
