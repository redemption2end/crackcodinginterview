// 3.7.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Shelter.h"
#include <time.h>




int _tmain(int argc, _TCHAR* argv[])
{
	srand(time(NULL));
	Shelter *shelter = new Shelter();

	for (int i = 0; i < 10; i++)
	{
		int type = rand() % 2;
		Animal *a = new Animal(type);
		a->value = i;

		printf("%d %d\n", type, i);

		shelter->enqueue(a);
	}


	Animal* a = shelter->dequeueAny();
	printf("type: %d, value: %d\n", a->type, a->value);


	a = shelter->dequeueAny();
	printf("type: %d, value: %d\n", a->type, a->value);

	a = shelter->dequeueCat();
	printf("type: %d, value: %d\n", a->type, a->value);


	a = shelter->dequeueCat();
	printf("type: %d, value: %d\n", a->type, a->value);

    a = shelter->dequeueAny();
	printf("type: %d, value: %d\n", a->type, a->value);

	return 0;
}

