// 2.7.cpp : Defines the entry point for the console application.
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

bool IsPalidrome(Node *l)
{
	if (l == NULL)
		return false;
	Node *slow = l, *fast = l;
	while (slow != NULL && fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
	}

	// slow is middle of the list
	Node *right = Reverse(slow), *temp = right;

	Node *left = l;
	bool isPali = true;
	while (right != NULL && left != right)
	{
		if (right->value != left->value)
		{
			isPali = false;
			break;
		}

		right = right->next;
		left = left->next;
	}

	Reverse(temp);

	return isPali;
}

int _tmain(int argc, _TCHAR* argv[])
{
	Node *head, *tail;
	head = tail = NULL;

	for (int i = 0; i < 12; i++)
	{
		if (head == NULL)
		{
			head = tail = new Node(i % 5, NULL);
		}
		else
		{
			int value = i > 6 ? 11 - i : i;
			tail->next = new Node(value, NULL);
			tail = tail->next;
		}
	}


	Node *temp = head;
	while (temp != NULL)
	{
		printf("%d ", temp->value);
		temp = temp->next;
	}


	printf("\nIs Palidrome: %s\n", IsPalidrome(head) ? "true" : "false");

	temp = head;
	while (temp != NULL)
	{
		printf("%d ", temp->value);
		temp = temp->next;
	}
	return 0;
}

