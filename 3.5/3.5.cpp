// 3.5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "MyQueue.h"

int _tmain(int argc, _TCHAR* argv[])
{

	MyQueue *myQueue = new MyQueue();

	myQueue->enqueue(1);
	myQueue->enqueue(2);

	int v = myQueue->dequeue();
	printf("%d \n", v);

	myQueue->enqueue(3);

	v = myQueue->dequeue();
	printf("%d \n", v);

	v = myQueue->dequeue();
	printf("%d \n", v);

	return 0;
}

