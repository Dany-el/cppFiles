#include "Apartment.h"
#include <iostream>
#include <cstring>

using std::cout;
using std::cin;

// ���������
// �������

// ������ ������
Room* Apartment::getRoom_arr()
{
	return room_arr;
}
// ���������� ������
int Apartment::getRoom_amount()
{
	return room_amount;
}

// �������
// �������
void Apartment::setRoom_arr(Room* p_room_arr)
{
	room_arr = p_room_arr;
}
// ���������� ������
void Apartment::setRoom_amount(int p_room_amount)
{
	room_amount = p_room_amount;
}

// ����������� �� �������
// ��������������
Apartment::Apartment()
{
	room_arr = new Room[1];
	room_amount = 0;
}

// ���������� � ������ ������
Apartment::Apartment(int p_room_amount)
{
	room_amount = p_room_amount;
	room_arr = new Room[room_amount];
}

// ���� ������ � ����������
void Apartment::Input()
{
	cout << "\nAmount of room: ";
	cin >> room_amount;
	cout << '\n';
	// ������ � ��������
	for (int i = 0; i < room_amount; i++)
	{
		room_arr[i].Input();
		cout << "\n";
	}
}

// ����� ������ :
// - ���������� ������
// - ������ 
void Apartment::Print()
{
	cout << "\nAmount of room: "<< room_amount << '\n';
	for (int i = 0; i < room_amount; i++)
	{
		room_arr[i].Print();
		cout << "\n";
	}
}

// ����������
Apartment::~Apartment()
{
	delete[] room_arr;
}

