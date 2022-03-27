#pragma once
#include <iostream>

using std::cout;

class A_function
{
public:
    template <typename type>
    void Init(type array[], int size)
    {
        for (size_t i = 0; i < size; i++)
        {
            for (size_t j = 0; j < size; j++)
            {
                array[i][j] = rand() % 10;
            }
        }
    }

    template <typename type>
    void Reverse(type array[], int size)
    {
        for (size_t i = size - 1; i != -1; i--)
        {
            for (size_t j = size - 1; j != -1; j--)
            {
                cout << ' ' << array[i][j];
            }
            cout << '\n';
        }
    }

    template <typename type>
    void Print(type array[], int size)
    {
        for (size_t i = 0; i < size; i++)
        {
            for (size_t j = 0; j < size; j++)
            {
                cout << ' ' << array[i][j];
            }
            cout << '\n';
        }
    }
};