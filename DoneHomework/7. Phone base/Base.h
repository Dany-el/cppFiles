#pragma once
#include <list>
#include <fstream>
#include "Contact.h"

class Base
{
    std::list<Contact *> array;
    static int amount_contact;
    std::ofstream w_create_file();
    std::ifstream r_create_file();

public:
    void add_contact();
    void add_contact(Contact *info);
    void pop_contact();
    void change_contact();

    void print_contact();
    Base print_contact_by_alp();
    Base print_contact_by_num();

    void find_contact_by_surname();
    void find_contact_by_pnumber();

    void write_file();
    void read_file();
};