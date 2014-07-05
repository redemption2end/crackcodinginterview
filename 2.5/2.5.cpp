// 2.5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Node.h"

Node* Sum(Node *a, Node *b)
{
	if (a == NULL)
		return b;
	if (b == NULL)
		return a;

	int carry = 0;
	Node *head = NULL, *tail = NULL;

	while (a != NULL && b != NULL)
	{
		int s = a->value + b->value + carry;
		carry = s / 10;
		if (head == NULL)
		{
			head = tail = new Node(s % 10, NULL);
		}
		else
		{
			tail->next = new Node(s % 10, NULL);
			tail = tail->next;
		}

		a = a->next;
		b = b->next;
	}

	while (a != NULL)
	{
		if (carry == 0)
		{
			tail->next = a;
			break;
		}
		int s = a->value + carry;
		carry = s / 10;
		tail->next = new Node(s % 10, NULL);
		tail = tail->next;

		a = a->next;
	}
	while (b != NULL)
	{
		if (carry == 0)
		{
			tail->next = b;
			break;
		}
		int s = b->value + carry;
		carry = s / 10;
		tail->next = new Node(s % 10, NULL);
		tail = tail->next;

		b = b->next;
	}

	if (carry != 0)
	{
		tail->next = new Node(carry, NULL);
		tail = tail->next;
	}
	return head;
}


int _tmain(int argc, _TCHAR* argv[])
{

	Node *aHead = NULL, *aTail = NULL;
	for (int i = 0; i < 10; i++)
	{
		if (aHead == NULL)
		{
			aHead = aTail = new Node(9, NULL);
		}
		else
		{
			aTail->next = new Node(9, NULL);
			aTail = aTail->next;
		}
	}

	Node *bHead = NULL, *bTail = NULL;
	for (int i = 0; i < 8; i++)
	{
		if (bHead == NULL)
		{
			bHead = bTail = new Node(9, NULL);
		}
		else
		{
			bTail->next = new Node(9, NULL);
			bTail = bTail->next;
		}
	}

	

	Node *sum = Sum(aHead, bHead);

	while (sum != NULL)
	{
		printf("%d ", sum->value);
		sum = sum->next;
	}

	return 0;
}

