#include "Roll.h"
#include <iostream>
#include <cstring>

using std::cout;
using std::cin;

// ���������
// �������

// ���
char* Roll::getName()
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
// ���
void Roll::setName(const char* p_name)
{
	if (&name != nullptr) {
		delete name;
	}
	name = new char[strlen(p_name) + 1];
	strcpy(name, p_name);
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
	name = nullptr;
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
Roll::Roll(const char* p_name, int p_length, int p_width, double p_price)
{
	// ���� �������� �� ���� ������
	// �� ���� ����� �� ����� �����-���� �������� 
	if (&name != nullptr) {
		// �������
		delete[] name;
	}
	// ���� ������ ����
	// ������� ����� � ������ p_name + 1
	name = new char[strlen(p_name) + 1];
	// ���������� ����� �������� ������
	strcpy(name, p_name);
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
	cout << "Name of roll: ";
	// ��������� ���������� � ��������� ������
	char p_name[100];
	cin.getline(p_name, 100);
	// ���� �������� �� ���� ������
	// �� ���� ����� �� ����� �����-���� �������� 
	if (&name != nullptr) {
		// �������
		delete[] name;
	}
	// ���� ������ ����
	// ������� ����� � ������ p_name + 1
	name = new char[strlen(p_name) + 1];
	// ���������� ����� �������� ������
	strcpy(name, p_name);
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
	delete[] name;
}
