#pragma once
#include <list>
using namespace std;

class Node
{
public:
	bool visited;
	list<Node*> *adjacent;
	char name;
public:
	Node(char);
	~Node();
};

