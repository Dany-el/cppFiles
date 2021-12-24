#include "Apartment.h"
#include <iostream>
#include <cstring>

using std::cout;
using std::cin;

// Аксессоры
// Геттеры

// Массив класса
Room* Apartment::getRoom_arr()
{
	return room_arr;
}
// Количество комнат
int Apartment::getRoom_amount()
{
	return room_amount;
}

// Сеттеры
// Комнаты
void Apartment::setRoom_arr(Room* p_room_arr)
{
	room_arr = p_room_arr;
}
// Количество комнат
void Apartment::setRoom_amount(int p_room_amount)
{
	room_amount = p_room_amount;
}

// Конструктор по дефолту
// Инициализируем
Apartment::Apartment()
{
	room_arr = new Room[1];
	room_amount = 0;
}

// Конструтор с вводом данных
Apartment::Apartment(int p_room_amount)
{
	room_amount = p_room_amount;
	room_arr = new Room[room_amount];
}

// Ввод данных с клавиатуры
void Apartment::Input()
{
	cout << "\nAmount of room: ";
	cin >> room_amount;
	cout << '\n';
	// Данные о комнатах
	for (int i = 0; i < room_amount; i++)
	{
		room_arr[i].Input();
		cout << "\n";
	}
}

// Вывод данных :
// - количество комнат
// - комнат 
void Apartment::Print()
{
	cout << "\nAmount of room: "<< room_amount << '\n';
	for (int i = 0; i < room_amount; i++)
	{
		room_arr[i].Print();
		cout << "\n";
	}
}

// Деструктор
Apartment::~Apartment()
{
	delete[] room_arr;
}

