#include "Room.h"
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::string;

// Аксессоры
// ----------------------------------------------
// Геттеры

// Имя
string Room::getName()
{
	return name;
}
// Высота
int Room::getHeight()
{
	return height;
}
// Ширина
int Room::getWidth()
{
	return width;
}
// Длина
int Room::getLength()
{
	return length;
}
// Поклейка
bool Room::getGlue()
{
	return glue;
}
// ----------------------------------------------
// Сеттеры

// Имя
void Room::setName(const string p_name)
{
	name = p_name;
}
// Высота
void Room::setHeight(int p_height)
{
	height = p_height;
}
// Ширина
void Room::setWidth(int p_width)
{
	width = p_width;
}
// Длина
void Room::setLength(int p_length)
{
	length = p_length;
}
// Поклейка
void Room::setGlue(bool p_glue)
{
	glue = p_glue;
}
// ----------------------------------------------

// Инициализация
// Конструктор по умолчанию
Room::Room()
{
	name = " ";
	height = 0;
	width = 0;
	length = 0;
	glue = false;
}

/*
Инициализация 
- конструктор с вводом данных  
- ввод пользователем

@param p_name	- название комнаты
@param p_height - высота комнаты
@param p_width  - ширина комнаты
@param p_length - длина комнаты
@param p_glue	- поклейка обоев

*/ 
Room::Room(const string p_name, int p_height, int p_width, int p_length, bool p_glue)
{
	// Присваивание новых значений в переменные
	// Название комнаты
	name = p_name;
	// Высота
	height = p_height;
	// Ширина
	width = p_width;
	// Длина
	length = p_length;
	// Клеить обои?
	glue = p_glue;
}

/*
Ввод данных с клавиатуры
*/
void Room::Input()
{
	cout << '\n';
	// Ввод названия комнаты
	cout << "Name of room: ";
	cin >> name;
	// Ввод высоты
	cout << "Height of room: ";
	cin >> height;
	// Ввод ширины
	cout << "Width of room: ";
	cin >> width;
	// Ввод длины
	cout << "Length of room: ";
	cin >> length;
	// Временная переменная с значениями "yes" или "no"
	string str_tmp;
	cout << "Glue roll?(yes or no): ";
	cin >> str_tmp;
	// Если пользователь ввел "да"
	if (str_tmp == "yes") {
		// Меняем значение на 1
		glue = true;
	}
	// Иначе остается на 0
	cout << '\n';
}

/*
Вывод данных комнаты
- название 
- высота
- длина
- ширина
- нужно ли клеить обои? Да/Нет
*/
void Room::Print()
{
	cout << '\n';
	cout << "Name of room: " << name;
	cout << "\nHeight of room: " << height;
	cout << "\nWidth of room: " << width;
	cout << "\nLength of room: " << length;
	cout << "\nGlue roll? ";
	if (glue) {
		cout << "Yes";
	}
	else {
		cout << "No";
	}
	cout << '\n';
}

// Деструктор 
Room::~Room()
{
	
}


