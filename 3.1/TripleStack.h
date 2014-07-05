#pragma once
class TripleStack
{
private:
	int* arry;
	int top[3], n;
	
public:
	TripleStack(int);
	~TripleStack();

	void push(int, int);

	int pop(int);

	void show();
};

