#pragma once
#include <stack>
using namespace std;
class StackWithMin
{
private:
	stack<int> original;
	stack<int> minStack;
public:
	StackWithMin();
	~StackWithMin();

	void push(int v)
	{
		if (original.empty())
		{
			minStack.push(v);
		}
		else
		{
			int top = minStack.top();
			if (top >= v)
				minStack.push(v);
		}

		original.push(v);
	};

	int pop()
	{
		int p = original.top();
		original.pop();

		int top = minStack.top();
		if (p == top)
		{
			minStack.pop();
		}

		return p;
	};

	int min()
	{
		if (!minStack.empty())
			return minStack.top();
		return -1;
	};
};

