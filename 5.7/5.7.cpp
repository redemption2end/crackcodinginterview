// 5.7.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>

using namespace std;

int findMissing(vector<int> *input)
{
	if (input == NULL)
		return -1;
	return findMissing(input, 0);
}

int findMissing(vector<int> *input, int col)
{
	if (col >= sizeof(int))
		return 0;

	vector<int> *zerobits = new vector<int>();
	vector<int> *onebits = new vector<int>();
	for (vector<int>::const_iterator iter = input->begin(); iter != input->end(); ++iter)
	{
		if ((*iter).getColumn(col) == 0)
			zerobits->push_back(*iter);
		else
			onebits->push_back(*iter);
	}
	int v = 0;
	if (zerobits->size() <= onebits->size())
	{
		v = findMissing(zerobits, col + 1);
		v = v << 1 | 0;
	}
	else
	{
		v = findMissing(onebits, col + 1);
		v = v << 1 | 1;
	}
	delete zerobits;
	delete onebits;
	return v;
}


int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

