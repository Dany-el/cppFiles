#include <iostream>
#include "Subject.h"

using std::string;
using std::cout;
using std::cin;

// Accessors

// Getter
string* Subject::getName(){
    return name;
}

// Setter
void Subject::setName(const string p_name)
{
    delete name;
    name = new string(p_name);
}

// Constructor by default
Subject::Subject()
{
    name = new string();
}

// Constructor with parameters 
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

// Destructor
Subject::~Subject()
{
    delete name;
}
