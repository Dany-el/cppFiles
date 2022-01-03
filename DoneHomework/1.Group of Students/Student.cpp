#include <iostream>
#include "Student.h"

using std::string;
using std::cin;
using std::cout;

/**
 * @brief Getter of Name
 * 
 * @return string* 
 */
string* Student::getName(){
    return name;
}

/**
 * @brief Getter of Subject
 * 
 * @return Subject* 
 */
Subject* Student::getSubject(){
    return subject;
}

/**
 * @brief Setter of Name
 * 
 * @param p_name - name of student
 */
void Student::setName(const string p_name){
    name = new string(p_name);
}

/**
 * @brief Setter of Subject
 * 
 * @param subject_amount - amount of subject
 */
void Student::setSubject(const unsigned int subject_amount){
    subject = new Subject[subject_amount];
}

/**
 * @brief Construct a new Student:: Student object
 * 
 */
Student::Student()
{
    name = new string();
    subject = new Subject[1];
}

/**
 * @brief Construct a new Student:: Student object
 * 
 * @param p_name          - name of subject
 * @param subject_amount  - amount of subjects
 */
Student::Student(const string p_name,const unsigned int subject_amount)
{
    name = new string(p_name);
    subject = new Subject[subject_amount];
}

/**
 * @brief Input info about
 *  amount of subjects, name of subject
 *  & student`s name and grades 
 * 
 * @return unsigned int* Grades_array 
 */
unsigned int* Student::Input(){
    // Amount of subject
    unsigned int subject_amount = 0;
    cout << "How many subjects do you have? ";
    cin >> subject_amount;
    // Create new one
    delete[] subject;
    setSubject(subject_amount);

    // Take info about subjects
    // WRITE WITHOUT SPACE !!!
    for (size_t i = 0; i < subject_amount; i++)
    {
        cout << '\n' << i + 1 << ". ";
        subject[i].Input();
    }

    // Create new array for grades
    
    // Array:
    // - grades
    unsigned int* grades_array = new unsigned int[subject_amount];
   
    // Clear console
    system("clear");

    // Take info about student
    // Name
    cout << "\nName of student: ";
    string p_name;
    cin >> p_name;
    delete name;
    name = new string(p_name);
    // Grades
    for (size_t i = 0; i < subject_amount; i++)
    {
        cout << "\n---" << *subject[i].getName() << "---\n";
        cout << "Grade: ";
        cin >> grades_array[i];
    }

    return grades_array;
}

Student::~Student()
{
    delete subject;
    delete name;
}
