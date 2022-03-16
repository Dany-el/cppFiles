#include <iostream>
#include <set>
#include "Base.h"

using std::cin;
using std::cout;

int Base::amount_contact = 0;

/**
 * @brief Add contact
 *
 */
void Base::add_contact()
{
    system("clear");
    cout << "Adding contact...\n";
    Contact *tmp = new Contact();
    tmp->add_info();

    // Empty Base
    if (amount_contact == 0)
    {
        array.push_front(tmp);
    }
    // Not Empty Base
    else
    {
        array.push_back(tmp);
    }
    amount_contact++;
}

void Base::add_contact(Contact *info)
{
    array.push_back(info);
}

/**
 * @brief Remove last contact
 *
 */
void Base::pop_contact()
{
    if (amount_contact == 0)
    {
        cout << "Base is already empty\n";
    }
    else
    {
        array.pop_back();
        amount_contact--;
    }
}

/**
 * @brief Print contacts
 *
 */
void Base::print_contact()
{
    system("clear");
    cout << "\t\t~~Contacts[" << amount_contact << "]~~\n";
    int j = 1;
    for (auto const &i : array)
    {
        cout << j << '.';
        // Using of overloading operator <<
        cout << *i;
        cout << "  \t-------------------------------\n";
        j++;
    }
    cout << '\n';
}

/**
 * @brief Change contact in base
 *
 */
void Base::change_contact()
{
    // Empty or not
    if (amount_contact == 0)
    {
        print_contact();
        cout << "\tBase is empty. You cannot change any contacts\n";
    }
    else
    {
        print_contact();
        int choise_contact = 0;
        cout << "Choose contact to change: ";
        cin >> choise_contact;
        // If user's choice is correct
        if (choise_contact > amount_contact && choise_contact > 0)
        {
            system("clear");
            cout << "Sorry,but there is only " << amount_contact << " contacts\n";
        }
        else
        {
            print_contact();
            int j = 1;
            Contact tmp;
            // Find contact in list
            for (auto const &i : array)
            {
                if (j == choise_contact)
                {
                    tmp = *i;
                    break;
                }
                j++;
            }
            system("clear");
            cout << tmp << '\n';
            tmp.change_info();
            print_contact();
        }
    }
}

/**
 * @brief Sort base by alphabet
 * 
 * @return Base - sorted base
 */
Base Base::print_contact_by_alp()
{
    system("clear");
    // Sort by a to z 
    Contact *tmp;
    for (auto &i : array)
    {
        std::string* source = new std::string(*(i->getSurname()));
        for (auto &j : array)
        {
            std::string* compared = new std::string(*(j->getSurname()));           
            if (source->compare(*compared) < 0)
            {
                tmp = i;
                i = j;
                j = tmp;
            }
            delete compared;
        }
        delete source;
    }

    Base sorted_base;
    // Input into new base
    for (auto &i : array)
    {
        sorted_base.add_contact(i);
    }
    return sorted_base;
}

/**
 * @brief Sort base by phone numbers
 *
 * @return Base - sorted base
 */
Base Base::print_contact_by_num()
{
    system("clear");
    // Add range
    int range_first = 0, range_second = 0;
    cout << "Input range\nfrom: ";
    cin >> range_first;
    cout << "to: ";
    cin >> range_second;

    // Sort by low to great numbers
    Contact *tmp;
    for (auto &i : array)
    {
        for (auto &j : array)
        {
            if (j->getPhone_Number() > i->getPhone_Number())
            {
                tmp = i;
                i = j;
                j = tmp;
            }
        }
    }

    Base sorted_base;
    // Check the range
    for (auto &i : array)
    {
        if (i->getPhone_Number() > range_first && i->getPhone_Number() < range_second)
        {
            sorted_base.add_contact(i);
        }
    }
    return sorted_base;
}

/**
 * @brief Find surname in base
 * 
 */
void Base::find_contact_by_surname()
{
    std::string p_surname;
    cout << "Surname to search\n>> ";
    cin >> p_surname;
    for (auto &i : array){
        std::string* temp = new std::string(*(i->getSurname()));
        // Compare 2 strings 
        // If equal = 0 
        if (!temp->compare(p_surname))
        {
            delete temp;
            // Output contact
            system("clear");
            cout << *i << '\n';
            break;
        }
        delete temp;
    }
}

/**
 * @brief Find number in base
 * 
 */
void Base::find_contact_by_pnumber()
{
    int p_phone_number = 0;
    cout << "Phone number to search\n>> ";
    cin >> p_phone_number;
    for (auto &i : array)
    {
        if (p_phone_number == i->getPhone_Number())
        {
            // Output contact
            system("clear");
            cout << *i << '\n';
            break;
        }
    }
}