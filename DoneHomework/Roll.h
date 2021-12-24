#pragma once
class Roll
{
	// �������� 
	char* name;
	// �����
	int length;
	// ������
	int width;
	// ����
	double price;
public:
	char* getName();
	int getLength();
	int getWidth();
	double getPrice();

	void setName(const char* p_name);
	void setLength(int p_length);
	void setWidth(int p_width);
	void setPrice(int p_price);

	Roll();
	Roll(const char* p_name,
		 int p_length,
		 int p_width,
		 double p_price);
	void Input();
	void Print();
	~Roll();
};

