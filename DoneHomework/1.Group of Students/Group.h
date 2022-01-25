#pragma once
#include "Student.h"
#include <string>
class Group
{
private:
	// Group name
	string* name;
	// Students(array)
	Student* student_array;
	// Subjects(array)
	Subject* subject_array;
public:
	string* getName() const;
	Student* getStudent_array() const;
	Subject* getSubject_array() const;

	void setName(const string p_name);
	void setStudent(const size_t student_amount);
	void setSubject(const size_t subject_amount);

	Group();
	Group(const string p_name,const size_t student_amount,const size_t subject_amount);

	void Print(const size_t** grades_array,const size_t student_amount,const size_t subject_amount) const;
	void Input();

	void Max_grade(size_t** grades_array,const size_t student_amount,const size_t subject_amount);
	void Min_grade(size_t** grades_array,const size_t student_amount,const size_t subject_amount);

	~Group();
};
