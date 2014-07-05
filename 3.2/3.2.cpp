// 3.2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "StackWithMin.h"

int _tmain(int argc, _TCHAR* argv[])
{

	StackWithMin *s = new StackWithMin();

	s->push(3);

	printf("min: %d\n", s->min());

	s->push(2);
	printf("min: %d\n", s->min());



	s->push(2);
	printf("min: %d\n", s->min());


	s->push(2);
	printf("min: %d\n", s->min());

	s->push(3);

	printf("min: %d\n", s->min());
	s->push(1);

	printf("min: %d\n", s->min());

	s->pop();
	printf("min: %d\n", s->min());
	s->pop();
	s->pop();
	s->pop();
	s->pop();

	printf("min: %d\n", s->min());

	return 0;
}

