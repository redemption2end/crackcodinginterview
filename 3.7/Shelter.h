#pragma once
#include "Animal.h"
#include <list>
using namespace std;


class Shelter
{
private:
	list<Animal*> *animals;
public:
	Shelter(){
		animals = new list<Animal*>();
	};

	void enqueue(Animal *a)
	{
		animals->push_front(a);
	};

	Animal* dequeueAny()
	{
		if (!animals->empty())
		{
			Animal *a = animals->back();
			animals->pop_back();
			return a;
		}
		return NULL;
	};

	Animal* dequeueCat()
	{
		list<Animal*> *buf = new list<Animal*>();

		while (!animals->empty() && animals->back()->type != 0)
		{
			Animal* a = animals->back();
			buf->push_back(a);
			animals->pop_back();
		}

		Animal* result = NULL;
		if (!animals->empty())
		{
			result = animals->back();
			animals->pop_back();
		}

		while (!buf->empty())
		{
			Animal *a = buf->back();
			animals->push_back(a);
			buf->pop_back();
		}

		delete buf;

		return result;

	};
	~Shelter();
};

