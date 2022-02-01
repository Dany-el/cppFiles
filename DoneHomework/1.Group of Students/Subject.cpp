#include <iostream>
#include "Subject.h"

using std::cout;
using std::cin;

// Accessors

/**
 * @brief Getter of subject`s name
 * 
 * @return string* 
 */
string* Subject::getName() const{
    return name;
}

/**
 * @brief Setter of subject`s name
 * 
 * @param p_name - name of subject
 */
void Subject::setName(const string p_name)
{
    delete name;
    name = new string(p_name);
}

/**
 * @brief Construct a new Subject:: Subject object
 * 
 */
Subject::Subject()
{
    name = new string();
}

/**
 * @brief Construct a new Subject:: Subject object
 * 
 * @param p_name - name of subject
 */
Subject::Subject(const string p_name)
{
    name = new string(p_name);
}

/**
 * @brief Input info about subject
 * - name
 */
void Subject::Input(){
    delete name;
    string p_name;
    cout << "Name of subject: ";
    cin >> p_name;
    name = new string(p_name);
}

/**
 * @brief Destroy the Subject:: Subject object
 * 
 */
Subject::~Subject()
{
    delete name;
}
