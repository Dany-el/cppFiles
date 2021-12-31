#include "Roll.h"
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::string;

// Аксессоры
// ----------------------------------------------
// Геттеры

// Имя
string Roll::getName()
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
// ----------------------------------------------
// Имя
void Roll::setName(const string p_name)
{
	name = p_name;
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
	name = " ";
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
Roll::Roll(const string p_name, int p_length, int p_width, double p_price)
{
	// Записываем новое название рулона
	name = p_name;
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
	// Записываем название рулона
	cout << "Name of roll: ";
	cin >> name;
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

}
