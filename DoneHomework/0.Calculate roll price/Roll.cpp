#include "Roll.h"
#include <iostream>
#include <cstring>

using std::cout;
using std::cin;

// Аксессоры
// Геттеры

// Имя
char* Roll::getName()
{
	return name;
}
// Длина
int Roll::getLength()
{
	return length;
}
// Ширина
int Roll::getWidth()
{
	return width;
}
// Цена
double Roll::getPrice()
{
	return price;
}

// Сеттеры
// Имя
void Roll::setName(const char* p_name)
{
	if (&name != nullptr) {
		delete name;
	}
	name = new char[strlen(p_name) + 1];
	strcpy(name, p_name);
}
// Длина
void Roll::setLength(int p_length)
{
	length = p_length;
}
// Ширина
void Roll::setWidth(int p_width)
{
	width = p_width;
}
// Цена
void Roll::setPrice(int p_price)
{
	price = p_price;
}

// Инициализация по умолчанию
Roll::Roll()
{
	name = nullptr;
	length = 0;
	width = 0;
	price = 0;
}

/*
* Инициализация, конструктор с вводом 
* - вводит пользователь
@param p_name   - название рулона 
@param p_width  - ширина рулона
@param p_length - длина рулона
@param p_price  - цена рулона
*/
Roll::Roll(const char* p_name, int p_length, int p_width, double p_price)
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
	// Записываем новое название рулона
	strcpy(name, p_name);
	// Длина
	length = p_length;
	// Ширина
	width = p_width;
	// Цена
	price = p_price;
}

// Ввод с клавиатуры значений
void Roll::Input()
{
	cout << "Name of roll: ";
	// Временная переменная с названием рулона
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
	// Записываем новое название рулона
	strcpy(name, p_name);
	// Ввод длины
	cout << "Length of roll: ";
	cin >> length;
	// Ввод ширины
	cout << "Width of roll: ";
	cin >> width;
	// Ввод цены 
	cout << "Price of roll: ";
	cin >> price;
}

// Вывод данных о рулоне
void Roll::Print()
{
	cout << '\n';
	cout << "Name of roll: " << name;
	cout << "\nWidth of roll: " << width;
	cout << "\nLength of roll: " << length;
	cout << "\nPrice of roll: " << price;
	cout << '\n';
}

// Деструктор
Roll::~Roll()
{
	delete[] name;
}
