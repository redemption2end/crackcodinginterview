// 3.6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stack>
#include <time.h>

using namespace std;

void sortStack(stack<int> *s)
{
	stack<int> *t = new stack<int>();

	while (!s->empty())
	{
		int v = s->top();
		s->pop();

		if (t->empty())
		{
			t->push(v);
		}
		else
		{
			int r = t->top();
			while (v > r)
			{
				s->push(r);
				t->pop();
				if (t->empty())
					break;
				r = t->top();
			}

			t->push(v);
		}
	}

	while (!t->empty())
	{
		int v = t->top();
		t->pop();
		s->push(v);
	}

	delete t;
}

int _tmain(int argc, _TCHAR* argv[])
{

	srand(time(NULL));
	stack<int> *result = new stack<int>();

	for (int i = 0; i < 100; i++)
	{
		int s = rand() % 100;
		printf("%d ", s);
		result->push(s);
	}

	printf("\n");

	sortStack(result);

	while (!result->empty())
	{
		printf("%d ", result->top());
		result->pop();
	}

	delete result;

	return 0;
}

