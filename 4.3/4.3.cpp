// 4.3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Node.h"


Node* CreateBinaryTree(int *arr, int start, int end)
{
	if (start > end)
		return NULL;

	int mid = (start + end) >> 1;
	Node *n = new Node(arr[mid], NULL, NULL);

	n->left = CreateBinaryTree(arr, start, mid - 1);
	n->right = CreateBinaryTree(arr, mid + 1, end);

	return n;
}

int _tmain(int argc, _TCHAR* argv[])
{

	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	Node *tree = CreateBinaryTree(arr, 0, 9);

	while (tree != NULL)
	{
		printf("%d \n", tree->value);
		tree = tree->left;
	}

	return 0;
}

