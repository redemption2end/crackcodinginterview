#pragma once
#include <stack>
#include <exception>
using namespace std;
class StackWithMin {
private:
	stack<int> *original;
	stack<int> *min;

public:
	StackWithMin(){
		original = new stack<int>();
		min = new stack<int>();
	};
	~StackWithMin(){
		if (original != NULL)
			delete original;
		if (min != NULL)
			delete min;
	};

	void pop() {
		if (original->empty())
			throw exception("trying to pop an empty stack");
		int t = original->top();
		if (t == min->top())
			min->pop();
		original->pop();
	};

	int top(){
		if (original->empty())
			throw exception("trying to top an empty stack");
		return original->top();
	}

	void push(int v){
		if (original->empty())
		{
			original->push(v);
			min->push(v);
		}
		else {
			if (v <= min->top())
			{
				min->push(v);
			}
			original->push(v);
		}
	}

};

