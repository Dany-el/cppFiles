#pragma once
class Room
{
	// �������� 
	char* name;
	// ������
	int height;
	// ������
	int width;
	// �����
	int length;
	// ����� �� �������� �������(1 - �� ��� 0 - ���)
	bool glue;
public:
	char* getName();
	int getHeight();
	int getWidth();
	int getLength();
	bool getGlue();

	void setName(const char* p_name);
	void setHeight(int p_height);
	void setWidth(int p_width);
	void setLength(int p_length);
	void setGlue(bool p_glue);

	Room();
	Room(const char* p_name,
		int p_height,
		int p_width,
		int p_length,
		bool p_glue);
	void Input();
	void Print();
	~Room();
};

