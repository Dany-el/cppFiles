#include <iostream>
#include "Base.h"

int main()
{
    system("sudo rm -r Base.txt");

    Base tmp2;
    tmp2.add_contact();
    tmp2.add_contact();
    tmp2.add_contact();
    tmp2.print_contact();

    // tmp2.find_contact_by_pnumber();
    // tmp2.find_contact_by_surname();

    // tmp2 = tmp2.print_contact_by_alp();
    // tmp2.print_contact();

    // tmp2.write_file();

    tmp2.read_file();

    return 0;
}