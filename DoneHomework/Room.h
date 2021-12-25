#pragma once
#include <string>

using std::string;
class Room
{
	// �������� 
	string name;
	// ������
	int height;
	// ������
	int width;
	// �����
	int length;
	// ����� �� �������� �������(1 - �� ��� 0 - ���)
	bool glue;
public:
	string getName();
	int getHeight();
	int getWidth();
	int getLength();
	bool getGlue();

	void setName(const string p_name);
	void setHeight(int p_height);
	void setWidth(int p_width);
	void setLength(int p_length);
	void setGlue(bool p_glue);

	Room();
	Room(const string p_name,
		int p_height,
		int p_width,
		int p_length,
		bool p_glue);
	void Input();
	void Print();
	~Room();
};

