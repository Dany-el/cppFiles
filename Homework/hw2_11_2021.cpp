
#include <iostream>
#include <string.h>
#include <random>

//----------------------------------------------------

/*
Задание 1. Написать программу, которая дает пользова-
телю ввести 5 фамилий студентов, а затем сортирует их 
по возрастанию.
*/

// Массив с фамилиями
char** surname;
// Размер символов
const int COMPACITY = 100;
// Количество фамилий
const int AMOUNT_SURNAME = 5;

/**
 * Создание массива
 */
void make_array(){
    surname = new char*[AMOUNT_SURNAME];
    for (size_t i = 0; i < AMOUNT_SURNAME; i++)
    {
        surname[i] = new char[COMPACITY];
    }    
}

/**
 * Заполнение массива
 */
void fill_array(){
    for (size_t i = 0; i < AMOUNT_SURNAME; i++)
    {
        std::cin.getline(surname[i],COMPACITY);
    }    
}

/**
 * Вывод массива
 */
void print_array(){
    for (size_t i = 0; i < AMOUNT_SURNAME; i++)
    {
        std::cout<< i + 1 << ".";
        puts(surname[i]);
    }    
    std::cout<<std::endl;
}

/**
 * Фильтр фамилий по возрастанию
 * по алфавиту
 */
void filter_array(){
    int value;
    for (size_t i = 0; i < AMOUNT_SURNAME; i++)
    {
        if(AMOUNT_SURNAME!= (i + 1)){
            value = strcmp(surname[i],surname[i+1]);
            // surname[i] > surname[i+1]
            if(value < 1){
                char* tmp = surname[i];
                delete[] surname[i];
                surname[i] = surname[i + 1];
                delete[] surname[i + 1];
                surname[i + 1] = tmp;
            }
        }        
    }    
}

//----------------------------------------------------

/*
Задание 2. Есть 3 двумерных массива A, B, C. Количество 
строк и столбцов для них вводит пользователь с клавиа-
туры для каждого из них. Реализуйте:
*/

int** A,B,C;
const int SIZE_ROW_A = 3;
const int SIZE_COLUMN_A = 5;

const int SIZE_ROW_B = 2;
const int SIZE_COLUMN_B = 3;

const int SIZE_ROW_C = 4;
const int SIZE_COLUMN_C = 5;


int** make_array(int** arr,const int row,const int column){
    arr = new int*[row];
    for (size_t i = 0; i < row; i++)
    {
        arr[i] = new int[column];
    }    
    return arr;
}

void init_array(int** arr,const int row,const int column){
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < column; j++)
        {
            arr[i][j] = rand() % 10;
        }        
    }    
}

//----------------------------------------------------

int main(){
    /* 1 */
    // make_array();
    // fill_array();
    // filter_array();
    // print_array();
    // delete[] surname;
    /* 2 */
    srand(time(NULL));
    A = make_array(A,SIZE_ROW_A,SIZE_COLUMN_A);
    B = make_array(B,SIZE_ROW_B,SIZE_COLUMN_B);
    C = make_array(C,SIZE_ROW_C,SIZE_COLUMN_C);

    return 0;
}