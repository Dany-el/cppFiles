#include <iostream>
#include "Airplane.h"

using std::string;
using std::cout;

/**
 * @brief Overloading of <<
 * 
 * @param out - object of class ostream
 * @param tmp - object of class Airplane
 * @return std::ostream& 
 */
std::ostream& operator<<(std::ostream& out,const Airplane& tmp){
    return out << "Type: " << *tmp.type << "\nPassengers: " << tmp.passengers_now << '/' << tmp.passengers_max << '\n';
}

/**
 * @brief Overloading of >>
 * 
 * @param in - object of class istream
 * @param tmp - object of class Airplane
 * @return std::istream& 
 */
std::istream& operator>>(std::istream& in,Airplane& tmp){
    delete tmp.type;
    string str;
    cout << "Type: ";
    in >> str;
    tmp.type = new string(str);
    
    cout << "\nPassengers MAX: ";
    in >> tmp.passengers_max;
    
    cout << "\nPassengers NOW: ";
    in >> tmp.passengers_now;
    // If passengers are more than max amount
    while (tmp.passengers_now <= tmp.passengers_max)
    {
        system("clear");
        cout << "\nWrong value!";
        cout << "\nPassengers NOW: ";
        in >> tmp.passengers_now;
    }
    
    cout << '\n';
    return in;
}

/**
 * @brief Construct a new Airplane:: Airplane object
 * 
 */
Airplane::Airplane(){
    type = new string();
    passengers_now = 0;
    passengers_max = 0;
}

/**
 * @brief Construct a new Airplane:: Airplane object
 * 
 * @param p_type - user's type
 * @param p_passengers_now - user's amount of passengers in plane
 * @param p_passengers_max - user's max of passengers that can be
 */
Airplane::Airplane(const string p_type, const size_t p_passengers_now,const size_t p_passengers_max){
    type = new string(p_type);
    passengers_now = p_passengers_now;
    passengers_max = p_passengers_max;
}

/**
 * @brief Overloading of ==
 * 
 * @param tmp - object of class Airplane
 * @return true 
 * @return false 
 */
bool Airplane::operator==(const Airplane& tmp) const {
    return type->length() == tmp.type->length();
}

/**
 * @brief Overloading of ++(prefix)
 * 
 * @return Airplane& 
 */
Airplane& Airplane::operator++(){
    if (passengers_now < passengers_max)
    {
        passengers_now++;
        return *this;
    }
    return *this;
}

/**
 * @brief Overloading of --(prefix)
 * 
 * @return Airplane& 
 */
Airplane& Airplane::operator--(){
    if (passengers_now > 0)
    {
        passengers_now--;
        return *this;
    }
    return *this;
}

/**
 * @brief Overloading of >
 * 
 * @param tmp - object of class Airplane
 * @return true 
 * @return false 
 */
bool Airplane::operator>(const Airplane& tmp) const{
    return passengers_now > tmp.passengers_max;
}

/**
 * @brief Destroy the Airplane:: Airplane object
 * 
 */
Airplane::~Airplane(){
    delete type;
}