/**
 * @file example.cpp
 * @author Daniel Yablonskyi (daniilyablonskiy88@gmail.com)
 * @brief Here will be test features
 * @version 0.1
 * @date 2021-12-18
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>

using std::cout,std::cin,std::string;

int main(){

    cout<<"hello world\n";
    cout<<"And happy new year\n";
    string s = "Happy New Year my dear son\n";
    cout<<s;
    s.replace(0,5,"Hello");
    cout<<s;

    return 0;
}