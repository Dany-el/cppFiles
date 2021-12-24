#include "Room.h"
#include <iostream>
#include <cstring>

using std::cout;
using std::cin;
using std::string;

// Аксессоры
// Геттеры

// Имя
char* Room::getName()
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

// Сеттеры

// Имя
void Room::setName(const char* p_name)
{
	if (name != nullptr) {
		delete name;
	}
	name = new char[strlen(p_name) + 1];
	strcpy(name, p_name);
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

// Инициализация
// Конструктор по умолчанию
Room::Room()
{
	name = nullptr;
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
Room::Room(const char* p_name, int p_height, int p_width, int p_length, bool p_glue)
{
	// Если название не было пустым
	// То есть имело до этого какое-либо значение 
	if (&name != nullptr) {
		// Удаляем
		delete[] name;
	}
	// Если массив пуст
	// Создаем новый с длиной p_name + 1
	name = new char[strlen(p_name) + 1];
	// Записываем новое название комнаты
	strcpy(name, p_name);
	// Присваивание новых значений в переменные
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
	// ВВОД НАЗВАНИЯ КОМНАТЫ
	cout << "Name of room: ";
	// Временная переменная с название комнаты
	char p_name[100];
	cin.getline(p_name, 100);
	// Если название не было пустым
	// То есть имело до этого какое-либо значение 
	if (&name != nullptr) {
		// Удаляем
		delete[] name;
	}
	// Если массив пуст
	// Создаем новый с длиной p_name + 1
	name = new char[strlen(p_name) + 1];
	strcpy(name, p_name);
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
	delete name;
}


