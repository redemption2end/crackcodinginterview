// 17.13.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


class Node {
public:
	int data;
	Node *node1, *node2;
public:
	Node(int data)
	{
		this->data = data;
		node1 = node2 = NULL;
	};
};

void reform(Node *n, Node* &cur, Node* &head)
{
	if (n->node1 != NULL)
	{
		reform(n->node1, cur, head);
	}

	if (cur == NULL)
	{
		head = cur = n;
	}
	else
	{
		cur->node2 = n;
		n->node1 = cur;
		cur = n;
	}

	if (n->node2 != NULL)
	{
		reform(n->node2, cur, head);
	}
}

void printList(Node *head, Node *tail)
{
	printf("From head to tail\n");
	Node* temp = head;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->node2;
	}

	printf("\nFrom tail to head\n");
	temp = tail;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->node1;
	}
	printf("\n");
}

void simulation1()
{
	Node *root = new Node(5);

	Node *four = new Node(4);
	root->node1 = four;

	Node *three = new Node(3);
	four->node1 = three;

	Node *two = new Node(2);
	three->node1 = two;

	Node *one = new Node(1);
	two->node1 = one;


	Node *head = NULL, *tail = NULL;

	reform(root, tail, head);
	printList(head, tail);	
}



void simulation2()
{
	Node *one = new Node(1);
	Node *two = new Node(2);
	Node *three = new Node(3);
	Node *four = new Node(4);
	Node *five = new Node(5);

	one->node2 = two;
	two->node2 = three;
	three->node2 = four;
	four->node2 = five;
	
	Node* head = NULL, *tail = NULL;
	reform(one, tail, head);

	printList(head, tail);
}

void simulation3()
{
	Node *one = new Node(1);
	Node *two = new Node(2);
	Node *three = new Node(3);
	Node *four = new Node(4);
	Node *five = new Node(5);

	three->node1 = one;
	three->node2 = five;

	one->node2 = two;

	five->node1 = four;

	Node* head = NULL, *tail = NULL;
	reform(three, tail, head);

	printList(head, tail);
}


int _tmain(int argc, _TCHAR* argv[])
{
	simulation1();

	simulation2();

	simulation3();
	
	return 0;
}

