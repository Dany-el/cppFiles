#include <iostream>
#include <iomanip>
#include "TV.h"

int TV::count = 0;

int main()
{
	// First info
	TV* tmp = new TV("name1","name1",123);
	tmp->Print();

	// Change info
	tmp->Input();
	tmp->Print();

	// Copy info from another object
	TV* tmp2 = new TV(*tmp);
	tmp2->Print();

	// Amount of objects
	TV::PrintCount();

	delete tmp;
	delete tmp2;

	return 0;
}