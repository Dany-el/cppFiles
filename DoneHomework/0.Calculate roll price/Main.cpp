#include <iostream>
#include "Apartment.h"

using std::cout;

int main()
{
	Apartment* obj1 = new Apartment();
	obj1->Input();
	obj1->Print_price();
	
	delete obj1;
	
	return 0;
}
