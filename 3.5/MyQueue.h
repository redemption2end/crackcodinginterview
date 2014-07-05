#pragma once
#include <stack>
using namespace std;
class MyQueue
{
private:
	stack<int> s1;
	stack<int> s2;
public:
	MyQueue();
	~MyQueue();

	void enqueue(int v)
	{
		s1.push(v);
	};

	int dequeue()
	{
		if (s2.empty())
		{
			while (!s1.empty())
			{
				int v = s1.top();
				s1.pop();
				s2.push(v);
			}
		}
		if (!s2.empty())
		{
			int v = s2.top();
			s2.pop();
			return v;
		}

		return -1;
	};
};

