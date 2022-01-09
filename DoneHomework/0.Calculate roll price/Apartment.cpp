#include "Apartment.h"
#include "Price.h"
#include "Roll.h"
#include <iostream>

using std::cout;
using std::cin;

// �?��� ��������
int sum = 0;
// �������Қ �ȳ�����Қ
// �Ӟ������� �Ӟ��?� Roll
Roll* tmp = new Roll();

// �ߣȣ����
// ��??ȳ�

// �ң��� ��ң��
Room* Apartment::getRoom_arr()
{
	return room_arr;
}
// ����?ȣ?�� �����?
int Apartment::getRoom_amount()
{
	return room_amount;
}

// ��??ȳ�
// �����?�
void Apartment::setRoom_arr(Room* p_room_arr)
{
	room_arr = p_room_arr;
}
// ����?ȣ?�� �����?
void Apartment::setRoom_amount(int p_room_amount)
{
	room_amount = p_room_amount;
}

// ��ܣ?�?�?�� �� ��?��??
// ���?�����۳?��
Apartment::Apartment()
{
	room_arr = nullptr;
	room_amount = 0;
}

// ��ܣ?�??�� � ������ ���ܖ?
Apartment::Apartment(int p_room_amount)
{
	room_amount = p_room_amount;
	room_arr = new Room[room_amount];
}

// ���� ���ܖ? � ������??��
void Apartment::Input()
{
	tmp->Input();
	cout << "\nAmount of room: ";
	cin >> room_amount;
	cout << '\n';
	// ������� �ң��� �ٚ ����� ��?����?�� � �����?�?
	delete[] room_arr;
	room_arr = new Room[room_amount];
	// ���ܖ� � �����?�?
	for (int i = 0; i < room_amount; i++)
	{
		room_arr[i].Input();
		// ���� ���� �?��� ����??
		if(room_arr[i].getGlue()){
			// �����ٚ�� ԣ� ���ܖ� � �ң?�? �ȳ���?�� � �������
			// ����� ����� ??�? �� ���ܖ?
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

// ����� ����?ȣ?�� �?����� � ?�ܖ
void Apartment::Print_price(){
	cout << "Rolls to buy: " << Rolls_amount(sum,tmp->getLength() * tmp->getWidth()) << '\n';
	cout << "Price of rolls: " <<  Rolls_amount(sum,tmp->getLength() * tmp->getWidth()) * tmp->getPrice() << '\n';
	// ���ٚ�� Գ�����?� �ȳ�����?�
	delete tmp;
}

// ����� ���ܖ? :
// - ����?ȣ?�� �����?
// - �����? 
void Apartment::Print()
{
	cout << "\nAmount of room: "<< room_amount << '\n';
	for (int i = 0; i < room_amount; i++)
	{
		room_arr[i].Print();
		cout << "\n";
	}
}

// �ȣ?�?�?��
Apartment::~Apartment()
{
	delete[] room_arr;
}
// Пробуем