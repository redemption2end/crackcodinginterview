// 4.4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Node.h"
#include <vector>
#include <list>
#include <queue>
using namespace std;
vector<list<Node*>*>* CreateLists(Node *t)
{
	queue<Node*>* q = new queue<Node*>();
	Node *dummyNode = new Node(-1, NULL, NULL);
	q->push(dummyNode);

	q->push(t);


	vector<list<Node*>*> *result = new vector<list<Node*>*>();
	list<Node*> *l = NULL;
	while (!q->empty())
	{
		Node *n = q->front();
		q->pop();

		if (n == dummyNode)
		{
			if (!q->empty())
			{
				l = new list<Node*>();

				result->push_back(l);
				q->push(dummyNode);
			}

		}
		else
		{
			l->push_back(n);
			if (n->left != NULL)
				q->push(n->left);
			if (n->right != NULL)
				q->push(n->right);
		}
	}

	return result;

}


int _tmain(int argc, _TCHAR* argv[])
{

	Node *root = new Node(5, NULL, NULL);
	root->left = new Node(3, NULL, NULL);
	root->right = new Node(4, NULL, NULL);

	root->left->left = new Node(1, NULL, NULL);
	root->left->right = new Node(2, NULL, NULL);

	root->right->left = new Node(6, NULL, NULL);
	root->right->right = new Node(7, new Node(8, NULL, NULL), NULL);




	vector<list<Node*>*>* result = CreateLists(root);

	for (vector<list<Node*>*>::iterator iter = result->begin(); iter != result->end(); iter++)
	{
		printf("\n");
		for (list<Node*>::iterator iter1 = (*iter)->begin(); iter1 != (*iter)->end(); iter1++)
		{
			printf("%d ", (*iter1)->value);
		}
	}

	return 0;
}

