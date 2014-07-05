// 17.5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <map>
using namespace std;

void eval(char *s, char *g, int &hits, int &pesudoHits)
{
	hits = 0, pesudoHits = 0;

	map<char, int> sol, gue, hitMap;
	while (*s != 0 && *g != 0)
	{
		if (sol.find(*s) == sol.end())
		{
			sol[*s] = 1;
		}
		else
		{
			sol[*s] ++;
		}

		if (gue.find(*g) == gue.end())
		{
			gue[*g] = 1;
		}
		else
		{
			gue[*g] ++;
		}

		if (*s == *g)
		{
			if (hitMap.find(*s) == hitMap.end())
			{
				hitMap[*s] = 1;
			}
			else
			{
				hitMap[*s] ++;
			}

			hits++;
		}

		++s, ++g;
	}

	map<char, int>::const_iterator iter = sol.begin(), iter1, iter2;

	while (iter != sol.end())
	{
		if ((iter1 = gue.find(iter->first)) != gue.end())
		{
			int absDiff = abs(iter1->second - iter->second);
			if ((iter2 = hitMap.find(iter->first)) != hitMap.end())
			{
				pesudoHits += (absDiff - iter2->second);
			}
			else
			{
				pesudoHits += absDiff;
			}
		}
		++iter;
	}
}


int _tmain(int argc, _TCHAR* argv[])
{
	int hits, pesudoHits;
	eval("RGBY", "RGRR", hits, pesudoHits);
	printf("%d %d\n", hits, pesudoHits);
	return 0;
}

