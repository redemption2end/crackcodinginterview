// 3.4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <stack>

using namespace std;
void Hanoid(stack<int> *a, char A, stack<int> *b, char B, stack<int> *c, char C, int n)
{
	if (n > 0)
	{
		Hanoid(a, A, c, C, b, B, n - 1);
		int i = a->top();
		a->pop();
		c->push(i);
		printf("Move %d from %c to %c\n", i, A, C);

		Hanoid(b, B, a, A, c, C, n - 1);
	}
}

int _tmain(int argc, _TCHAR* argv[])
{

	stack<int> *a = new stack<int>();
	for (int i = 9; i >= 0; i--)
	{
		a->push(i);
	}

	stack<int> *b = new stack<int>(), *c = new stack<int>();
	Hanoid(a, 'A', b, 'B', c, 'C', 10);


	while (!c->empty())
	{
		printf("%d ", c->top());
		c->pop();
	}

	return 0;
}

