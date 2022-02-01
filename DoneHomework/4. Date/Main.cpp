#include <iostream>
#include "Date.h"

int main(){
    Date tmp;
    tmp.Input();

    Date tmp2;
    tmp2.Input();

    tmp.Print();
    tmp2.Print();

    Date tmp3 = tmp + 90;

    tmp3.Print();
    std::cout << "Days: " << tmp - tmp2 << '\n';

    return 0;
}