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

bool IsPalidrome1(Node *l)
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



bool IsPalindrome(Node *head, Node *middle, Node *&mirror, bool isEven)
{
	if ((!isEven && head->next->next == middle) || (isEven && head->next == middle))
	{
		mirror = middle;
		return head->value == middle->value;
	}
	bool ret = IsPalindrome(head->next, middle, mirror, isEven);
	if (ret == false)
		return false;

	mirror = mirror->next;
	return head->value == mirror->value;
}

bool IsPalindrome(Node *head)
{
	if (head == NULL)
		return false;
	Node *first = head, *second = head;
	while (second != NULL && second->next != NULL)
	{
		first = first->next;
		second = second->next->next;
	}
	bool isEven = true;
	if (second != NULL)
	{
		first = first->next;
		isEven = false;
	}

	if (first == NULL)
		return true;

	Node *mirror = NULL;
	return IsPalindrome(head, first, mirror, isEven);

}

bool IsPalindrome(Node *head, Node* &mirror, int length)
{
	if (head == NULL || length == 0)
	{
		mirror = NULL;
		return true;
	}
	else if (length == 1)
	{
		mirror = head->next;
		return true;
	}
	else if (length == 2)
	{
		mirror = head->next->next;
		return head->value == head->next->value;
	}

	bool ret = IsPalindrome(head->next, mirror, length - 2);
	if (ret == false)
		return false;
	ret = head->value == mirror->value;

	mirror = mirror->next;
	return ret;
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
			int value = i > 5 ? 11 - i : i;
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

	// Third version testing
	Node *mirror = NULL;
	printf("\nIs Palidrome: %s\n", IsPalindrome(head, mirror, 12) ? "true" : "false");

	temp = head;
	while (temp != NULL)
	{
		printf("%d ", temp->value);
		temp = temp->next;
	}
	return 0;
}

