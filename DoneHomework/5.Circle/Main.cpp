#include <iostream>
#include "Circle.h"

using std::cout;
using std::cin;

int main(){
    Circle tmp(10,20);

    Circle tmp2(11,19);

    // test
    // radius
    if(tmp == tmp2){
        cout << "1st radius = 2nd radius";
    }
    // length
    if(tmp > tmp2){
        cout << "1st length > 2nd length\n";
    }
    tmp+=1;
    cout << tmp;
    tmp-=2;
    cout << tmp;

    return 0;
}