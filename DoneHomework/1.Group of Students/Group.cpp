#include <iostream>
#include <iomanip>
#include "Group.h"

using std::cout;
using std::cin;

/**
 * @brief Getter of group name
 * 
 * @return string*
 */
string* Group::getName(){
    return name;
}

/**
 * @brief Getter of array of students
 * 
 * @return Student* 
 */
Student* Group::getStudent_array(){
    return student_array;
}

/**
 * @brief Getter of Subject
 * 
 * @return Subject* 
 */
Subject* Group::getSubject_array(){
    return subject_array;
}

/**
* @brief Setter of group name
* 
* @param p_name - name of group 
*/
void Group::setName(const string p_name){
    delete name;
    name = new string(p_name);
}

/**
 * @brief Setter of array 
 * 
 * @param student_amount - amount of students in the group
 */
void Group::setStudent(const size_t student_amount){
    delete[] student_array;
    student_array = new Student[student_amount];
}

/**
 * @brief Setter of Subject
 * 
 * @param subject_amount - amount of subject
 */
void Group::setSubject(const size_t subject_amount){
    delete[] subject_array;
    subject_array = new Subject[subject_amount];
}

/**
 * @brief Construct a new Group:: Group object
 * 
 */
Group::Group(){
    name = new string();
    student_array = new Student[1];
    subject_array = new Subject[1];
}

/**
 * @brief Construct a new Group:: Group object
 * 
 * @param p_name         - name of group
 * @param student_amount - amount of students
 * @param subject_amount - amount of subjects
 */
Group::Group(const string p_name,const size_t student_amount,const size_t subject_amount)
{
    name = new string(p_name);
    student_array = new Student[student_amount];
    subject_array = new Subject[subject_amount];
}

/**
 * @brief Input info about group, students` names, subjects` names
 * 
 */
void Group::Input(){
    string p_name;
    cout << "\nName of group: ";
    cin >> p_name;
    delete name; 
    name = new string(p_name);

    size_t subject_amount;
    cout << "\nHow many subjects do you have? ";
    cin >> subject_amount;
    // Create new one
    delete[] subject_array;
    setSubject(subject_amount);
    // Take info about subjects
    // WRITE WITHOUT SPACE !!!
    for (size_t i = 0; i < subject_amount; i++)
    {
        cout << '\n' << i + 1 << ". ";
        subject_array[i].Input();
    }

    // Amount of student
    size_t student_amount;
    cout << "\nHow many students are in the group? ";
    cin >> student_amount;
    delete[] student_array;
    setStudent(student_amount);
   
    // Array with grades 
    size_t** grades_array = new size_t*[student_amount];
    // Input grades of students
    for (size_t i = 0; i < student_amount; i++)
    {   
        system("clear");
        grades_array[i] = student_array[i].Input(subject_array,subject_amount);    
    }

    system("clear");
    Group::Print(grades_array,student_amount,subject_amount);
}

/**
 * @brief Max grade of subjects
 * 
 * @param grades_array   - array with grades 
 * @param student_amount - amount of students
 * @param subject_amount - amount of subjects
 */
void Group::Max_grade(size_t** grades_array,const size_t student_amount,const size_t subject_amount){
    // Student name of the max subject`s grade
    int* subject_name_index = new int[subject_amount];
    
    // Search max grade
    for (size_t j = 0; j < subject_amount; j++)
    {
        // Max grade
        size_t max_grade = 1;
        for (size_t i = 0; i < student_amount; i++)
        {
            // If value is more than max_grade
            if (grades_array[i][j] > max_grade)
            {
                subject_name_index[j] = i;
                max_grade = grades_array[i][j];
            }
        }
        cout << "\n---Max---\nSubject: "<< *subject_array[j].getName() << '\n';
        cout << "\t" << *student_array[subject_name_index[j]].getName() << "  " << max_grade;
    }
    // Delete array
    delete[] subject_name_index;
}

/**
 * @brief Min grade of subjects
 * 
 * @param grades_array   - array with grades 
 * @param student_amount - amount of students
 * @param subject_amount - amount of subjects
 */
void Group::Min_grade(size_t** grades_array,const size_t student_amount,const size_t subject_amount){
    int* subject_name_index = new int[subject_amount];
    // Search max grade
    for (size_t j = 0; j < subject_amount; j++)
    {
        // Min grade
        size_t min_grade = 12;
        for (size_t i = 0; i < student_amount; i++)
        {
            // If value is more than max_grade
            if (grades_array[i][j] < min_grade)
            {
                subject_name_index[j] = i;
                min_grade = grades_array[i][j];
            }
        }
        cout << "\n---Min---\nSubject: "<< *subject_array[j].getName() << '\n';
        cout << "  " << *student_array[subject_name_index[j]].getName() << "  " << min_grade;
    }
    // Delete array
    delete[] subject_name_index;
}

/**
 * @brief Print info about group
 * 
 * @param grades_array   - array with grades 
 * @param student_amount - amount of students
 * @param subject_amount - amount of subjects
 */
void Group::Print(size_t** grades_array,const size_t student_amount,const size_t subject_amount){
    cout << "Group: " << *name << '\n';
    
    // Subjects
    for (size_t i = 0; i < subject_amount; i++)
    {
        cout << '\t' << *subject_array[i].getName() << " ";
    }
    cout << '\n';

    // Avg student`s grade(sum of student`s grades)
    double student_avg_grade = 0;
    // Avg group`s grade(sum of student_avg_grade)
    double group_avg_grade = 0;
    // Avg subject`s grade(sum of subject`s grades)
    double* subject_avg_grade = new double[subject_amount];

    for (size_t i = 0; i < student_amount; i++)
    {
        // To not sum another student`s grades
        student_avg_grade = 0;
        // Print student`s name
        cout << *student_array[i].getName() << "   ";
        
        // Print grades
        for (size_t j = 0;j < subject_amount; j++)
        {
            // Sum to divide by amount of subjects
            student_avg_grade += grades_array[i][j];
            // Sum to divide by amount of students
            subject_avg_grade[j] += grades_array[i][j];

            cout << std::setw(5) << grades_array[i][j] << "  |";
        }  
        
        // Next subject
        // Sum avg student`s grade to divide by amount of students 
        // To get group`s avg grade
        group_avg_grade += student_avg_grade / subject_amount;
        // Print student`s avg grade 
        printf("\t %.2f\n",student_avg_grade / subject_amount);  
    }

    // Print subject`s avg grade
    for (size_t i = 0; i < subject_amount; i++)
    {
        printf("\t%.2f",subject_avg_grade[i] / student_amount);
    }
    // Delete array
    delete[] subject_avg_grade;

    cout << "\n---------------------------------------\n";

    Max_grade(grades_array,student_amount,subject_amount);

    cout << "\n\n---------------------------------------\n";

    Min_grade(grades_array,student_amount,subject_amount);

    cout << "\n\n---------------------------------------\n";

    // Avg group 
    printf("\nGroup avg: %.2f\n",group_avg_grade / student_amount);
}

/**
 * @brief Destroy the Group:: Group object
 * 
 */
Group::~Group()
{
    delete name;
    delete[] student_array;
    delete[] subject_array;
}