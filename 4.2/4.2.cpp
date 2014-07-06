// 4.2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Node.h"

bool IsConnected(Node *t, Node *s)
{

	if (t == s)
		return true;

	t->visited = true;


	for (list<Node*>::iterator iter = t->adjacent->begin(); iter != t->adjacent->end(); ++iter)
	{
		if (!(*iter)->visited)
		{
			if (IsConnected(*iter, s))
				return true;
		}
	}
	
	return false;
}

int _tmain(int argc, _TCHAR* argv[])
{
	Node *a = new Node('a');
	Node *b = new Node('b');
	Node *c = new Node('c');
	Node *d = new Node('d');
	Node *e = new Node('e');
	Node *f = new Node('f');
	Node *g = new Node('g');

	a->adjacent->push_back(b);
	a->adjacent->push_back(c);
	//a->adjacent->push_back(d);
	d->adjacent->push_back(a);

	c->adjacent->push_back(d);

	b->adjacent->push_back(e);

	e->adjacent->push_back(g);
	e->adjacent->push_back(f);

	//printf("Is connected: %s\n", IsConnected(a, b) ? "true" : "false");

	//printf("Is connected: %s\n", IsConnected(a, e) ? "true" : "false");

	printf("Is connected: %s\n", IsConnected(b, g) ? "true" : "false");

	return 0;
}

