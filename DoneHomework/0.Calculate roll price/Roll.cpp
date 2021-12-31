#include "Roll.h"
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::string;

// ���������
// ----------------------------------------------
// �������

// ���
string Roll::getName()
{
	return name;
}

// �����
int Roll::getLength()
{
	return length;
}
// ������
int Roll::getWidth()
{
	return width;
}
// ����
double Roll::getPrice()
{
	return price;
}

// �������
// ----------------------------------------------
// ���
void Roll::setName(const string p_name)
{
	name = p_name;
}
// �����
void Roll::setLength(int p_length)
{
	length = p_length;
}
// ������
void Roll::setWidth(int p_width)
{
	width = p_width;
}
// ����
void Roll::setPrice(int p_price)
{
	price = p_price;
}

// ������������� �� ���������
Roll::Roll()
{
	name = " ";
	length = 0;
	width = 0;
	price = 0;
}

/*
* �������������, ����������� � ������ 
* - ������ ������������
@param p_name   - �������� ������ 
@param p_width  - ������ ������
@param p_length - ����� ������
@param p_price  - ���� ������
*/
Roll::Roll(const string p_name, int p_length, int p_width, double p_price)
{
	// ���������� ����� �������� ������
	name = p_name;
	// �����
	length = p_length;
	// ������
	width = p_width;
	// ����
	price = p_price;
}

// ���� � ���������� ��������
void Roll::Input()
{
	// ���������� �������� ������
	cout << "Name of roll: ";
	cin >> name;
	// ���� �����
	cout << "Length of roll: ";
	cin >> length;
	// ���� ������
	cout << "Width of roll: ";
	cin >> width;
	// ���� ���� 
	cout << "Price of roll: ";
	cin >> price;
}

// ����� ������ � ������
void Roll::Print()
{
	cout << '\n';
	cout << "Name of roll: " << name;
	cout << "\nWidth of roll: " << width;
	cout << "\nLength of roll: " << length;
	cout << "\nPrice of roll: " << price;
	cout << '\n';
}

// ����������
Roll::~Roll()
{

}
