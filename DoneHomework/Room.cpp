#include "Room.h"
#include <iostream>
#include <cstring>

using std::cout;
using std::cin;
using std::string;

// ���������
// �������

// ���
char* Room::getName()
{
	return name;
}
// ������
int Room::getHeight()
{
	return height;
}
// ������
int Room::getWidth()
{
	return width;
}
// �����
int Room::getLength()
{
	return length;
}
// ��������
bool Room::getGlue()
{
	return glue;
}

// �������

// ���
void Room::setName(const char* p_name)
{
	if (name != nullptr) {
		delete name;
	}
	name = new char[strlen(p_name) + 1];
	strcpy(name, p_name);
}
// ������
void Room::setHeight(int p_height)
{
	height = p_height;
}
// ������
void Room::setWidth(int p_width)
{
	width = p_width;
}
// �����
void Room::setLength(int p_length)
{
	length = p_length;
}
// ��������
void Room::setGlue(bool p_glue)
{
	glue = p_glue;
}

// �������������
// ����������� �� ���������
Room::Room()
{
	name = nullptr;
	height = 0;
	width = 0;
	length = 0;
	glue = false;
}

/*
������������� 
- ����������� � ������ ������  
- ���� �������������

@param p_name	- �������� �������
@param p_height - ������ �������
@param p_width  - ������ �������
@param p_length - ����� �������
@param p_glue	- �������� �����

*/ 
Room::Room(const char* p_name, int p_height, int p_width, int p_length, bool p_glue)
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
	// ���������� ����� �������� �������
	strcpy(name, p_name);
	// ������������ ����� �������� � ����������
	// ������
	height = p_height;
	// ������
	width = p_width;
	// �����
	length = p_length;
	// ������ ����?
	glue = p_glue;
}

/*
���� ������ � ����������
*/
void Room::Input()
{
	cout << '\n';
	// ���� �������� �������
	cout << "Name of room: ";
	// ��������� ���������� � �������� �������
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
	strcpy(name, p_name);
	// ���� ������
	cout << "Height of room: ";
	cin >> height;
	// ���� ������
	cout << "Width of room: ";
	cin >> width;
	// ���� �����
	cout << "Length of room: ";
	cin >> length;
	// ��������� ���������� � ���������� "yes" ��� "no"
	string str_tmp;
	cout << "Glue roll?(yes or no): ";
	cin >> str_tmp;
	// ���� ������������ ���� "��"
	if (str_tmp == "yes") {
		// ������ �������� �� 1
		glue = true;
	}
	// ����� �������� �� 0
	cout << '\n';
}

/*
����� ������ �������
- �������� 
- ������
- �����
- ������
- ����� �� ������ ����? ��/���
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

// ���������� 
Room::~Room()
{
	delete name;
}


