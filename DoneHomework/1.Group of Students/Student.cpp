#include <iostream>
#include "Student.h"

using std::cin;
using std::cout;

/**
 * @brief Getter of Name
 * 
 * @return string* 
 */
string* Student::getName() const{
    return name;
}

/**
 * @brief Setter of Name
 * 
 * @param p_name - name of student
 */
void Student::setName(const string p_name){
    delete name; 
    name = new string(p_name);
}

/**
 * @brief Construct a new Student:: Student object
 * 
 */
Student::Student()
{
    name = new string();
}

/**
 * @brief Construct a new Student:: Student object
 * 
 * @param p_name          - name of subject
 */
Student::Student(const string p_name)
{
    name = new string(p_name);
}

/**
 * @brief Input info about
 *  amount of subjects, name of subject
 *  & student`s name and grades 
 * 
 * @param subject        - array with subjects` names
 * @param subject_amount - amount of subjects
 * 
 * @return size_t* Grades_array 
 */
size_t* Student::Input(Subject* subject,const size_t subject_amount){
    // Create new array for grades

    // Array:
    // - grades
    size_t* grades_array = new size_t[subject_amount];
   
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

/**
 * @brief Destroy the Student:: Student object
 * 
 */
Student::~Student()
{
    delete name;
}
