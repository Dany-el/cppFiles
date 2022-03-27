#pragma once
#include <iostream>

using std::cout;

struct A_function
{
    /**
     * @brief Initialize array
     *
     * @tparam type
     * @param array - any array
     * @param size  - size of array
     */
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

    /**
     * @brief Reverse array
     *
     * @tparam type
     * @param array - any array
     * @param size  - size of array
     */
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

    /**
     * @brief Print array
     *
     * @tparam type
     * @param array - any array
     * @param size  - size of array
     */
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