#pragma once
#include <string.h>
using std::string;
class Subject
{
private:
	string* name;
public:
	string* getName();
	
	void setName(const string p_name);

	Subject();
	Subject(const string p_name);

	void Input();

	~Subject();
};



