#pragma once

class String{
    // String
    char* str;
    // Lenght of string
    // Why we should use it?
    // It's useless
    unsigned int length; 
public:
    static int ojects_count;

    char* getString();
    unsigned int getLength();

    void setString(const char* p_str);
    void setLength(const unsigned int p_length);

    String();
    String(const char* p_str, const unsigned int p_length);
    String(const char* p_str);
    String(const String& tmp);

    void InputString();
    void PrintString();

    void MyStrcpy(const String& obj);
    bool MyStrStr(const char * str);
    int MyChr(char c);
    int MyStrLen();
    void MyStrCat(const String& obj);
    void MyDelChr(char c);
    int MyStrCmp(const String& obj);

    char* operator++();
    char* operator--();

    ~String();
};