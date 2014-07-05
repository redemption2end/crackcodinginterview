#pragma once
class TripleStack1
{
private:
	int n, current;
	int *idx, *value;

	int top[3];
public:
	TripleStack1(int);
	~TripleStack1();

	void push(int, int);
	int pop(int);

	void show();
};

