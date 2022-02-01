#include <iostream>
#include "String.h"


int main(){
    String* tmp = new String("hello");
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

    delete tmp;
    return 0;
}