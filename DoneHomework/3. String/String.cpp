#include "String.h"
#include <iostream>
#include <string.h>

#define STRING_LEN 80

using std::cout;
using std::cin;

int String::ojects_count = 0;

/**
 * @brief Getter of the length
 * 
 * @return unsigned int 
 */
unsigned int String::getLength() 
{
    return length;
}

/**
 * @brief Getter of the string
 * 
 * @return char* 
 */
char* String::getString() 
{
    return str;
}

/**
 * @brief Setter of the string
 * 
 * @param p_str - customer's string
 */
void String::setString(const char* p_str) 
{
    delete[] str;
    str = new char[strlen(p_str)+1];
    strcpy(str,p_str);
}

/**
 * @brief Setter of the length
 * 
 * @param p_length - customer's length
 */
void String::setLength(const unsigned int p_length) 
{
    length = p_length;
}

/**
 * @brief Construct a new String:: String object
 * Copy values
 * 
 * @param tmp - Source
 */
String::String(const String& tmp){
    str = new char[strlen(tmp.str)+1];
    length = tmp.length;
}

/**
 * @brief Construct a new String:: String object
 * 
 */
String::String() 
{
    ojects_count++;
    str = new char[STRING_LEN];
    length = 0;
}

/**
 * @brief Construct a new String:: String object
 * 
 * @param p_str    - customer's string
 * @param p_length - customer's length
 */
String::String(const char* p_str, const unsigned int p_length) 
{
    ojects_count++;
    str = new char[strlen(p_str)+1];
    strcpy(str,p_str);
    length = p_length;
}

/**
 * @brief Construct a new String:: String object
 * 
 * @param p_str - customer's string
 */
String::String(const char* p_str){
    ojects_count++;
    str = new char[strlen(p_str)+1];
    strcpy(str,p_str);
}

/**
 * @brief Input string
 * 
 */
void String::InputString(){
    char p_str [STRING_LEN];

    cout << "String: ";
    cin.getline(p_str,STRING_LEN);

    delete[] str;
    str = new char[strlen(p_str)+1];
    strcpy(str,p_str);
}

/**
 * @brief Print string
 * 
 */
void String::PrintString(){
    cout << "String >> ";
    puts(str);
}

/**
 * @brief Copy string
 * 
 * @param obj 
 */
void String::MyStrcpy(const String& obj){
    delete[] str;
    str = new char[strlen(obj.str)+1];
    strcpy(str,obj.str);
}

/**
 * @brief Find string at substring
 * 
 * @param str - string to find
 * @return true Found
 * @return false Not Found
 */
bool String::MyStrStr(const char* p_str){
    if (strstr(str,p_str))
    {
        return 1;
    }
    return 0;
}

/**
 * @brief Find symbol at string 
 * 
 * @param c - symbol
 * @return int (index of symbol) 
 */
int String::MyChr(char c){
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] == c)
        {
            return i;
        }
    }
    return -1;
}

/**
 * @brief Lenght of string
 * 
 * @return int (string length)
 */
int String::MyStrLen(){
    return strlen(str);
}

/**
 * @brief Сoncatenation of two strings
 * 
 * @param obj - Destination
 */
void String::MyStrCat(const String& obj){
    strcat(str,obj.str);
}
/**
 * @brief Delete symbol at string
 * 
 * @param c - symbol
 */
void String::MyDelChr(char c){
    // tmp char
    // without symbol 
    char p_str[strlen(str)];
    // Counter for tmp char
    int j = 0;
    for (int i = 0; i < strlen(str); i++)
    {
        // If found
        if(str[i] != c){
            p_str[j] = str[i];
            j++;
        }
    }
    // End with terminator
    p_str[strlen(str)-1] = '\0';
    // Copy to main string 
    delete[] str;
    str = new char[strlen(p_str) + 1];
    strcpy(str,p_str);
}

/**
 * @brief Compare two strings
 * 
 * @param obj - string to compare
 * @return int  
 */
int String::MyStrCmp(const String& obj){
    // str < obj.str
    if(strcmp(str,obj.str) < 0){
        return -1;
    }
    // str == obj.str
    else if(strcmp(str,obj.str) == 0) {
        return 0;
    }
    // str > obj.str
    return 1;
}

/**
 * @brief Add to the end 1 symbol 
 * 
 * @return String 
 */
char* String::operator++(){
    // Create new char with old char elements
    char* tmp = new char[strlen(str)+1];
    strcpy(tmp,str);
    // Delete old
    delete[] str;
    str = new char[strlen(tmp)+2];
    // Copy new 
    strcpy(str,tmp);
    delete[] tmp;
    // Change the new 
    str[strlen(str)] = 'X';
    str[strlen(str) + 1] = '\0';
    return str;
}

/**
 * @brief Remove the last symbol 
 * 
 * @return String 
 */
char* String::operator--(){
    // tmp char
    // without symbol 
    char p_str[strlen(str) + 1];
    // Counter for tmp char
    for (int i = 0; i < strlen(str); i++)
    {
        p_str[i] = str[i];
    }
    // End with terminator
    p_str[strlen(str)-1] = '\0';
    // Copy to main string 
    delete[] str;
    str = new char[strlen(p_str) + 1];
    strcpy(str,p_str);
    return str;
}

char& operator[](const size_t index){
    if(index > 0 && index < strlen(str)){
        return str[index];
    }
    return str[0];
}

/**
 * @brief Destroy the String:: String object
 * 
 */
String::~String() 
{
    ojects_count--;
    delete[] str;
}
