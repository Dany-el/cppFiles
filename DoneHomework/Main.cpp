#include <iostream>
#include "Roll.h"
#include "Apartment.h"
#include "Room.h"

using std::cout;
using std::cin;

int Perimeter(int p_width,int p_length){
	return 2*(p_width+p_length);
}

int Area(int perimeter,int p_heigth){
	int area = perimeter * p_heigth;
	return area;
}



int main()
{
	Apartment* obj1 = new Apartment();
	obj1->Input();
	//Room* obj2 = new Room();
	//obj2->Input();
	// cout << "\nArea of the room: " << 
	// 		Area(Perimeter(obj1->getWidth(),obj1->getLength()),
	// 		obj1->getHeight()) << '\n';
	return 0;
}
