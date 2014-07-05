// 5.2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
using namespace std;
void printf(double input)
{
	string repre("0.");
	int maximum = 32, i = 0;
	while (i < maximum && input != 0)
	{
		input *= 2;
		if (input >= 1)
		{
			repre.append("1");
			input -= 1;
		}
		else
		{
			repre.append("0");
		}
		i++;
	}

	if (i == maximum)
		printf("Error\n");
	else
		printf("%s\n", repre.c_str());
}

int _tmain(int argc, _TCHAR* argv[])
{
	double base = 0.5, value = 0;
	for (int i = 0; i < 20; i++)
	{
		value += base;
		base = base * 0.5;
	}
	double input = 0.5;
	printf(input);

	input = 0.75;
	printf(input);

	input = 0.7222222;
	printf(value);

	return 0;
}

