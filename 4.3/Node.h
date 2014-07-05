#pragma once
class Node
{
public:
	Node *left, *right;
	int value;
public:

	Node(int, Node*, Node*);
	~Node();
};

