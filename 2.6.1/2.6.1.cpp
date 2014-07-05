// 2.6.1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Node.h"

Node* FindLoopBegin(Node* l)
{
	if (l == NULL)
		return NULL;

	Node* t = l, *s = l;
	do{
		t = t->next;
		s = s->next->next;
	} while (t != s && t != NULL && s != NULL && s->next != NULL);

	if (t == NULL || s == NULL || s->next == NULL)
		return NULL;

	t = l;
	while (t != s)
	{
		t = t->next;
		s = s->next;
	}

	return t;
}

int _tmain(int argc, _TCHAR* argv[])
{
	Node *head = NULL, *tail = NULL, *mid = NULL;
	for (int i = 0; i < 10; i++)
	{
		
		if (tail == NULL)
		{
			head = tail = new Node(i, NULL);
		}
		else 
		{
		
			tail->next = new Node(i, NULL);
			if (i == 1)
				mid = tail->next;
			tail = tail->next;
		}
	}

	tail->next = mid;


	Node *loopBegin = FindLoopBegin(head);

	printf("%d ", loopBegin->value);
	

	return 0;
}

