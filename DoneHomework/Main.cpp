#include <iostream>
#include "Roll.h"
#include "Apartment.h"
#include "Room.h"

using std::cout;
using std::cin;

int main()
{
	Room* obj1 = new Room();
	//obj1->setName("Name");
	obj1->Input();

	return 0;
}
