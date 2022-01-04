#include <iostream>
#include "Subject.h"

using std::cout;
using std::cin;

// Accessors

// Getters
string* Subject::getName(){
    return name;
}

// Setters
void Subject::setName(const string p_name)
{
    if(name != NULL){
        delete name;
    } 
    name = new string(p_name);
}

// Constructor by default
Subject::Subject()
{
    if(name != NULL){
        delete name;
    } 
    name = new string();
}

// Constructor with parameters 
Subject::Subject(const string p_name)
{
    if(name != NULL){
        delete name;
    } 
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
    if(name != NULL){
        delete name;
    } 
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
