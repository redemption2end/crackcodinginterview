#include "stdafx.h"
#include "Node.h"


Node::Node(char name)
{
	this->visited = false;
	this->adjacent = new list<Node*>();
	this->name = name;
}


Node::~Node()
{
}
