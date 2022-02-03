#include <iostream>
#include "String.h"

char operator+(const String obj1,const String obj2){
    strcat(obj1.getString(),obj2.getString());
    return obj1.getString();
}

int main(){
    String tmp ("hello");
    String tmp2;
    puts("How many symbol 'X' do you want to add?");
    int user_amount;
    std::cin >> user_amount;
    for (size_t i = 0; i < user_amount; i++)
    {
        tmp2.setString(++tmp);
        puts(tmp2.getString());
    }
    puts("How many symbol 'X' do you want to remove?");
    std::cin >> user_amount;
    for (size_t i = 0; i < user_amount; i++)
    {
        tmp2.setString(--tmp);
        puts(tmp2.getString());
    }
    
    //puts(tmp2.getString());

    //String tmp3 = --tmp;
    //puts(tmp3.getString());

    // tmp->InputString();
    // tmp->PrintString();

    //std::cout << tmp->MyStrStr("hello");
    //std::cout << tmp->MyChr('o');

    //tmp->MyDelChr('h');
    //tmp->PrintString();

    //String tmp1("hello1");

    //std::cout << '\n' << tmp->MyStrCmp(tmp1) << '\n';
    
    // tmp->MyStrCat(tmp1);
    // tmp->PrintString();

    //std::cout << tmp->ojects_count;

    return 0;
}
