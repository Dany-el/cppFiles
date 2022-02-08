#include "Circle.h"

/**
 * @brief 
 * 
 * @param stream - ostream's object
 * @param tmp - object 
 * @return std::ostream& 
 */
std::ostream& operator<<(std::ostream& stream,const Circle& tmp){
    return stream << "Radius: " << tmp.radius << "\nLength: " << tmp.length << '\n';
}

/**
 * @brief 
 * 
 * @param stream - istream's object
 * @param tmp - object
 * @return std::istream 
 */
std::istream& operator>>(std::istream& stream,Circle& tmp){
    std::cout << "Radius: ";
    stream >> tmp.radius;
    std::cout << "Lenght: ";
    stream >> tmp.length; 
    return stream;
}

/**
 * @brief 
 * 
 * @param tmp - object 
 * @return true equal
 * @return false not equal
 */
bool Circle::operator==(const Circle& tmp){
    return radius == tmp.radius;
}

/**
 * @brief 
 * 
 * @param tmp - object
 * @return true more
 * @return false less
 */
bool Circle::operator>(const Circle& tmp){
    return length > tmp.length;
}

/**
 * @brief 
 * 
 * @param number 
 * @return Circle& 
 */
Circle& Circle::operator+=(const size_t number){
    radius+=number;
    return *this;
}

/**
 * @brief 
 * 
 * @param number 
 * @return Circle& 
 */
Circle& Circle::operator-=(const size_t number){
    radius -= number;
    return *this;
}

/**
 * @brief Construct a new Circle:: Circle object
 * 
 */
Circle::Circle(){
    radius = 0;
    length = 0;
}

/**
 * @brief Construct a new Circle:: Circle object
 * 
 * @param p_radius 
 * @param p_length 
 */
Circle::Circle(const size_t p_radius,const size_t p_length){
    radius = p_radius;
    length = p_length;
}

/**
 * @brief Destroy the Circle:: Circle object
 * 
 */
Circle::~Circle(){

}