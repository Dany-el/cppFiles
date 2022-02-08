#pragma once 
#include <iostream>

class Circle{
    size_t radius;
    size_t length;
    friend std::ostream& operator<<(std::ostream& stream,const Circle& tmp);
    friend std::istream& operator>>(std::istream& stream,Circle& tmp);
public:
    Circle();
    Circle(const size_t p_radius,const size_t p_length);

    bool operator==(const Circle& tmp);
    bool operator>(const Circle& tmp);
    Circle& operator+=(const size_t number);
    Circle& operator-=(const size_t number);
    
    ~Circle();  
};