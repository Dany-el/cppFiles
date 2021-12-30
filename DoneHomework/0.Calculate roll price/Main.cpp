#include <iostream>
#include "Roll.h"
#include "Apartment.h"
#include "Room.h"

using std::cout;
using std::cin;

/*
 * Периметр комнаты

 @param p_width  - ширина комнаты
 @param p_length - длина комнаты

 @return Периметр комнаты
*/
int Perimeter(int p_width,int p_length){
	return 2*(p_width+p_length);
}

/*
 * Площадь комнаты

@param perimeter - периметр комнаты
@param p_height  - высота комнаты

@return Площадь комнаты
*/
int Area(int perimeter,int p_heigth){
	int area = perimeter * p_heigth;
	return area;
}


int main()
{
	Apartment* obj1 = new Apartment();
	obj1->Input();
	
	return 0;
}
