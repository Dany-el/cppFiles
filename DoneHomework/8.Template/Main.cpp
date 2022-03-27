#include <iostream>
#include <random>
#include "A_function.h"
// #include "B_function.h"
// #include "C_function.h"

int main() {
    srand(time(0));
    A_function A_temp;
    int array[3][3];

    A_temp.Init(array,3);
    A_temp.Print(array,3);
    cout << '\n';
    A_temp.Reverse(array,3);
 
    return 0;
}