// 4.1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "Node.h"



bool IsBalanced(Node *t, int &height)
{
	if (t == NULL)
	{
		height = 0;
		return true;
	}

	int h1 = 0, h2 = 0;
	bool stage = IsBalanced(t->left, h1) && IsBalanced(t->right, h2);
	height = (h1 >= h2 ? h1 : h2) + 1;
	return stage && (h1 - h2 >= -1 && h1 - h2 <= 1);
}

bool IsBalanced(Node *t)
{
	int height = 0;
	return IsBalanced(t, height);
}

int _tmain(int argc, _TCHAR* argv[])
{

	Node *root = new Node();
	printf("%s\n", IsBalanced(root) ? "true" : "false");



	root->left = new Node();
	printf("%s\n", IsBalanced(root) ? "true" : "false");
	root->right = new Node();


	root->left->left = new Node();
	printf("%s\n", IsBalanced(root) ? "true" : "false");

	root->right->right = new Node();
	printf("%s\n", IsBalanced(root) ? "true" : "false");

	return 0;
}

