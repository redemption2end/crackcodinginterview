// 2.6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Node.h"

Node* Reverse(Node *a)
{
	if (a == NULL)
		return a;

	Node *p = a, *q = a->next; 
	// Reverse the first node
	p->next = NULL;

	while (q != NULL)
	{
		Node *temp = q->next;
		q->next = p;
		p = q;
		q = temp;
	}

	return p;
}


int _tmain(int argc, _TCHAR* argv[])
{

	Node *head = NULL, *tail = NULL;
	for (int i = 0; i < 2; i++)
	{
		if (head == NULL)
		{
			head = tail = new Node(i, NULL);
		}
		else
		{
			tail->next = new Node(i, NULL);
			tail = tail->next;
		}
	}


	Node *r = Reverse(head);

	while (r != NULL)
	{
		printf("%d ", r->value);
		r = r->next;
	}

	return 0;
}

