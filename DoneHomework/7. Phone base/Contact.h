#pragma once
#include <string>

class Contact
{
    std::string *name;
    std::string *surname;
    int phone_number;

public:
    std::string* getName() const;
    std::string* getSurname() const;
    int getPhone_Number() const;

    void setName(const std::string p_name);
    void setSurname(const std::string p_surname);
    void setPhone_Number(const int p_phone_number);

    Contact();
    Contact(const std::string p_name, const std::string p_surname, const int p_phone_number);

    void add_info();
    void change_info();

    friend std::ostream &operator<<(std::ostream &out, const Contact &tmp);
    
    ~Contact();
};