#include "Apartment.h"
#include "Price.h"
#include "Roll.h"
#include <iostream>

using std::cout;
using std::cin;

// ����� ��������
int sum = 0;
// ��������� ����������
// ���������� ������� Roll
Roll* tmp = new Roll();

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
	room_arr = nullptr;
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
	tmp->Input();
	cout << "\nAmount of room: ";
	cin >> room_amount;
	cout << '\n';
	// ������� ������ ��� ����� ���������� � ��������
	delete[] room_arr;
	room_arr = new Room[room_amount];
	// ������ � ��������
	for (int i = 0; i < room_amount; i++)
	{
		room_arr[i].Input();
		// ���� ���� ����� ������
		if(room_arr[i].getGlue()){
			// ��������� ��� ������ � ������ ��������� � �������
			// ����� ����� ���� �� ������
			sum =  Sum_of_areas (Area_Room(Perimeter_Room(room_arr[i].getWidth(),
										    room_arr[i].getLength()
										   ),
							room_arr[i].getHeight()
					 			),
							sum
							);
		}
		cout << "\n";
	}
	
}

// ����� ���������� ������� � ����
void Apartment::Print_price(){
	cout << "Rolls to buy: " << Rolls_amount(sum,tmp->getLength() * tmp->getWidth()) << '\n';
	cout << "Price of rolls: " <<  Rolls_amount(sum,tmp->getLength() * tmp->getWidth()) * tmp->getPrice() << '\n';
	// ������� ��������� ����������
	delete tmp;
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

