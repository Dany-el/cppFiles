#include "Apartment.h"
#include "Price.h"
#include "Roll.h"
#include <iostream>

using std::cout;
using std::cin;

// Сумма площадей
int sum = 0;
// Временная переменная
// Объявление объекта Roll
Roll* tmp = new Roll();

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
	room_arr = nullptr;
	room_amount = 0;
}

// Конструтор с вводом данных
Apartment::Apartment(int p_room_amount)
{
	room_amount = p_room_amount;
	room_arr = new Room[room_amount];
}

/**
 * @brief Ввод данных о квартире
 * - комната(длина, ширина, высота)
 */
void Apartment::Input()
{
	tmp->Input();
	cout << "\nAmount of room: ";
	cin >> room_amount;
	cout << '\n';
	// Создаем массив для ввода информации о комнатах
	delete[] room_arr;
	room_arr = new Room[room_amount];
	// Данные о комнатах
	for (int i = 0; i < room_amount; i++)
	{
		room_arr[i].Input();
		// Если обои нужно клеить
		if(room_arr[i].getGlue()){
			// Добавляем все данные в расчет периметра и площади
			// После ввода этих же данных
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

// Вывод количества рулонов и цены
void Apartment::Print_price(){
	cout << "Rolls to buy: " << Rolls_amount(sum,tmp->getLength() * tmp->getWidth()) << '\n';
	cout << "Price of rolls: " <<  Rolls_amount(sum,tmp->getLength() * tmp->getWidth()) * tmp->getPrice() << '\n';
	// Удаляем временную переменную
	delete tmp;
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