// 3.1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "TripleStack.h"
#include "TripleStack1.h"

int _tmain(int argc, _TCHAR* argv[])
{

	TripleStack1 *ts = new TripleStack1(10);
	ts->push(0, 1);
	ts->push(0, 2);

	ts->show();

	ts->push(1, 3);
	ts->push(1, 4);

	ts->show();

	ts->push(2, 6);
	ts->push(2, 5);
	ts->push(2, 7);


	ts->show();

	ts->pop(1);
	ts->show();

	ts->pop(2);
	ts->show();

	ts->push(0, 10);
	ts->push(1, 19);
	ts->push(2, 18);
	

	ts->show();

	ts->pop(2);
	ts->pop(2);
	ts->show();

	return 0;
}

