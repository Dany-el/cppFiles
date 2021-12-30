#pragma once
#include <string>

using std::string;
class Roll
{
	// Название 
	string name;
	// Длина
	int length;
	// Ширина
	int width;
	// Цена
	double price;
public:
	string getName();
	int getLength();
	int getWidth();
	double getPrice();

	void setName(const string p_name);
	void setLength(int p_length);
	void setWidth(int p_width);
	void setPrice(int p_price);

	Roll();
	Roll(const string p_name,
		 int p_length,
		 int p_width,
		 double p_price);
	void Input();
	void Print();
	~Roll();
};

