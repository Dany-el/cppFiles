#pragma once
#include "Room.h"
class Apartment
{
	// ������ �������
	Room* room_arr;
	// ���������� ������
	int room_amount;
public:
	Room* getRoom_arr();
	int getRoom_amount();

	void setRoom_arr(Room* p_room_arr);
	void setRoom_amount(int p_room_amount);

	Apartment();
	Apartment(int p_room_amount);
	void Input();
	void Print();
	~Apartment();
};

