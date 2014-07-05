// 2.3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Node.h"

Node* Find(Node *head, int k)
{
	if (head == NULL)
	{
		return NULL;
	}

	int length = 0;
	Node *temp = head;
	while (temp != NULL)
	{
		length++;
		temp = temp->next;
	}

	int i = length - 1 - k;
	temp = head;
	while (i > 0)
	{
		temp = temp->next;
		i--;
	}

	return temp;
}

int _tmain(int argc, _TCHAR* argv[])
{

	Node* head = NULL;
	Node *tail = NULL;

	for (int i = 0; i < 10; i++)
	{
		if (tail == NULL)
		{
			head = tail = new Node(i, NULL);
		}
		else
		{
			tail->next = new Node(i, NULL);
			tail = tail->next;
		}
	}

	printf("%d %d", 4, Find(head, 4)->value);

	return 0;
}

