#pragma once
#include "Room.h"
#include "Roll.h"
class Apartment
{
	// Массив комнаты
	Room* room_arr;
	// Количество комнат
	int room_amount;
public:
	Room* getRoom_arr();
	int getRoom_amount();

	void setRoom_arr(Room* p_room_arr);
	void setRoom_amount(int p_room_amount);

	Apartment();
	Apartment(int p_room_amount);
	void Print_price();
	void Input();
	void Print();
	~Apartment();
};

