#include "stdafx.h"
#include "Shelter.h"




Shelter::~Shelter()
{
	if (animals != NULL)
	{
		delete animals;
		animals = NULL;
	}
}
