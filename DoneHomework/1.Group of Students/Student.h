#pragma once
#include <string.h>
#include "Subject.h"

using std::string;
class Student
{
private:
	// Name of student
	string* name;	
	// Subjects
	Subject* subject;
public:
	string* getName();
	Subject* getSubject();

	void setName(const string p_name);
	void setSubject(const unsigned int subject_amount);

	Student();
	Student(const string p_name,const unsigned int subject_amount);

	unsigned int* Input();

	~Student();
};


