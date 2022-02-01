#pragma once
#include <string.h>
#include "Subject.h"

using std::string;
class Student
{
private:
	// Name of student
	string* name;	
public:
	string* getName() const;

	void setName(const string p_name);

	Student();
	Student(const string p_name);

	size_t* Input(Subject* subject,const size_t subject_amount);

	~Student();
};


