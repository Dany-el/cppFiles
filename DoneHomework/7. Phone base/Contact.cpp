#include <iostream>
#include <string.h>
#include "Contact.h"

using std::cin;
using std::cout;

/**
 * @brief Getter of name
 *
 * @return std::string*
 */
std::string *Contact::getName() const
{
    return surname;
}

/**
 * @brief Getter of surname
 *
 * @return std::string*
 */
std::string *Contact::getSurname() const
{
    return surname;
}

/**
 * @brief Getter of phone number
 *
 * @return int
 */
int Contact::getPhone_Number() const
{
    return phone_number;
}

/**
 * @brief Setter of name
 *
 * @param p_name - user's name
 */
void Contact::setName(const std::string p_name)
{
    delete name;
    name = new std::string(p_name);
}

/**
 * @brief Setter of surname
 *
 * @param p_surname - user's surname
 */
void Contact::setSurname(const std::string p_surname)
{
    delete surname;
    surname = new std::string(p_surname);
}

/**
 * @brief Setter of phone number
 *
 * @param p_phone_number - user's phone number
 */
void Contact::setPhone_Number(const int p_phone_number)
{
    phone_number = p_phone_number;
}

/**
 * @brief Construct a new Contact:: Contact object
 *
 */
Contact::Contact()
{
    name = new std::string();
    surname = new std::string();
    phone_number = 0;
}

/**
 * @brief Construct a new Contact:: Contact object
 *
 * @param p_name         - user's name
 * @param p_surname      - user's surname
 * @param p_phone_number - user's phone number
 */
Contact::Contact(const std::string p_name, const std::string p_surname, const int p_phone_number)
{
    setName(p_name);
    setSurname(p_surname);
    setPhone_Number(p_phone_number);
}

/**
 * @brief Add info about contact
 *
 */
void Contact::add_info()
{
    std::string temp;
    // Name
    cout << "Name >> ";
    cin >> temp;
    setName(temp);
    // Surname
    cout << "Surname >> ";
    cin >> temp;
    setSurname(temp);
    // Phone number
    cout << "Phone number >> ";
    cin >> phone_number;
}

/**
 * @brief Change info about contact
 *
 */
void Contact::change_info()
{
    int tmp = 0;
    std::string temp;
    cout << "What info about contact would you change?\n1.Name\n2.Surname\n3.Phone number\n>> ";
    cin >> tmp;
    switch (tmp)
    {
    case 1:
        cout << "Name >> ";
        cin >> temp;
        setName(temp);
        break;
    case 2:
        cout << "Surname >> ";
        cin >> temp;
        setSurname(temp);
        break;
    case 3:
        cout << "Phone number >> ";
        cin >> phone_number;
        break;
    default:
        break;
    }
}

/**
 * @brief Output list
 * 
 * @param out - source like "cout"
 * @param tmp - contact 
 * @return std::ostream& 
 */
std::ostream &operator<<(std::ostream &out, const Contact &tmp)
{
    return out << "\tName: " << *tmp.name
               << "\tSurname: " << *tmp.surname
               << "\n\tPhone number: " << tmp.phone_number << '\n';
}

/**
 * @brief Destroy the Contact:: Contact object
 *
 */
Contact::~Contact()
{
    delete name;
    delete surname;
}