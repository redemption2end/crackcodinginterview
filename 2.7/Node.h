#pragma once
class Node
{
public:
	int value;
	Node *next;
public:
	Node(int, Node*);
	~Node();
};

