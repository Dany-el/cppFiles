#include <iostream>
#include "Airplane.h"

using std::cout;
using std::cin;

int main(){
    Airplane tmp("Comfort",12,20);
    Airplane tmp2("Comfort",29,40);

    if (tmp == tmp2)
    {
        cout << "Types are equal\n";
    }
    if (tmp > tmp2)
    {
        cout << "1st plane has more than 2nd\n";
    }
    else{
        cout << "2nd plane has more than 1st\n";
    }
    cout << tmp;
    --tmp;
    cout << tmp;

    cout << tmp2;
    --tmp2;
    cout << tmp2;

    return 0;
}