#include <iostream>
#include <iomanip>
#include <string.h>

//------------------------------------------------------

/*
Задание 1. Транспонирование матрицы — это операция, 
после которой столбцы прежней матрицы становят-
ся строками, а строки столбцами. Напишите функцию 
транспонирования матрицы.
*/


//------------------------------------------------------

//
const int NUMBERS = 1;
//
const int NAMES = 0;
//
int changed_amount = 1;

int base_amount = 0;
/*
Задание 2. Создайте динамический массив, хранящий 
в первой строке имя, а во второй — телефон. Организуй-
те поиск по имени и по номеру телефона и возможность 
ввода и изменения данных
*/

/*
Создаем массив для вписывания имени и телефона 
*/
std::string** makeArr(){
    std::string** PhoneBook = new std::string*[2];
    return PhoneBook;
}

// Инициализируем массив 
/*
@param arr - массив(записная книжка)
*/
void initArr(std::string** arr){
    arr[NAMES] = new std::string[changed_amount];
    arr[NUMBERS] = new std::string[changed_amount];
}

// Вывод массива(записной книги)
void printArr(std::string** arr){
    std::cout<<"Name"<<"\t"<<"Phone Number\n";
    for (size_t i = 0; i < changed_amount; i++)
    {        
        std::cout<<i<<"."<<arr[NAMES][i] << "\t";
        std::cout<<arr[NUMBERS][i];      
    }
    std::cout<<std::endl;        
}

// Запись в массив номер телефона 
std::string** inputNumber(std::string** arr){
    //
    std::string input;   
    // Номер контакта 
    std::cout<<"Phone Number\n:> ";
    std::cin>>input;

    std::string* newArr = new std::string[changed_amount + 1];
    arr[NUMBERS] = newArr;
    arr[NUMBERS][base_amount] = input;
    return arr;
}

// Запись в массив имя
/*std::string** inputName(std::string** arr){
    std::string input;   
    // Имя контакта
    std::cout<<"Name\n:> ";
    std::cin>>input;

    std::string** newArr = new std::string*[changed_amount+1];
    
    for (size_t i = 0; i < changed_amount; i++)
    {
        for (size_t j = 0; j < changed_amount; j++)
        {
           newArr[i] = arr[i];
        }       
    }
    delete[] arr;
    newArr[NAMES][base_amount] = input;

    return newArr;
}*/

// Поиск по номеру телефона
void searchByPhoneNumber(std::string arr){
    std::string input_number;

}

int main(){
    int person_choise;
    std::string** PhoneBook = makeArr();
    initArr(PhoneBook);
    do{
        std::cout<<"\nWhat would you want?\n1.Find phone number having name\n2.Find name having number\n"<<
        "3.Add new number and name\n4.Change contact"<<
        "\n5.Show all contacts\n6.Exit\n";
        std::cin>>person_choise;
        switch (person_choise)
        {
        case 1:
            
            break;
        case 2:
            
            break;
        case 3:
            //PhoneBook = inputName(PhoneBook);            
            PhoneBook = inputNumber(PhoneBook);
            changed_amount++;
            printArr(PhoneBook);
            break;
        case 4:
            
            break;
        case 5:
            printArr(PhoneBook);
            break;
        }
    }while(person_choise!=6);

    delete[] PhoneBook;
    return 0;
}