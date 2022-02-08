#pragma once
#include <string>

using std::string;

class Airplane{
    // Тип самолета
    string* type;
    // Кол. пассажиров сейчас
    size_t passengers_now;
    // Максимальное кол. пассажиров
    size_t passengers_max;
    friend std::ostream& operator<<(std::ostream& out,const Airplane& tmp); 
    friend std::istream& operator>>(std::istream& in,Airplane& tmp);
public:
    Airplane();
    Airplane(const string p_type, const size_t p_passengers_now,const size_t p_passengers_max);
    
    bool operator==(const Airplane& tmp) const;
    Airplane& operator++();
    Airplane& operator--();
    bool operator>(const Airplane& tmp) const;

    ~Airplane();
};