// 2.4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Node.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

using namespace std;

Node* Split(Node *head, int x)
{
	if (head == NULL)
	{
		return NULL;
	}

	Node *less = NULL, *larger = NULL, *lessHead = NULL, *largerHead = NULL, *current = NULL;
	if (head->value < x)
	{
		lessHead = less = head;
	}
	else 
	{
		largerHead = larger = head;
	}

	current = head->next;
	head->next = NULL;

	while (current != NULL)
	{
		if (current->value < x)
		{
			if (less == NULL)
			{
				lessHead = less = current;
			}
			else
			{
				less->next = current;
				less = less->next;
			}			
		} 
		else
		{
			if (larger == NULL)
			{
				largerHead = larger = current;
			}
			else
			{
				larger->next = current;
				larger = larger->next;
			}
		}

		Node *temp = current;
		current = current->next;
		temp->next = NULL;
	}
	if (less != NULL)
	{
		less->next = largerHead;
	}
	if (lessHead != NULL)
		return lessHead;

	return largerHead;
}

int _tmain(int argc, _TCHAR* argv[])
{
	srand(time(NULL));
	int count = 100;
	while (--count > 0)
	{
		Node *head = NULL, *tail = NULL;

		printf("\n=== %d ===\n", count);
		for (int i = 0; i < 10; i++)
		{
			int N = 100;
			if (i < 2)
				N = 50;
			if (tail == NULL)
			{
				head = tail = new Node(rand() % N, NULL);
			}
			else
			{

				tail->next = new Node(rand() % N, NULL);
				tail = tail->next;
			}
		}

		Node *temp = head;
		while (temp != NULL)
		{
			printf("%d ", temp->value);
			temp = temp->next;
		}

		printf("\n");

		temp = Split(head, 50);

		while (temp != NULL)
		{
			printf("%d ", temp->value);
			temp = temp->next;
		}

	}
	
	return 0;
}

