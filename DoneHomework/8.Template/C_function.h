#pragma once
#include <iostream>

using std::cout, std::cin;

struct C_function
{
    /**
     * @brief Print reverse array
     *
     * @tparam type
     * @param array
     * @param size
     */
    template <typename type>
    void print_rev_array(type array[], int size)
    {
        for (size_t i = size - 1; i != -1; i--)
        {
            cout << ' ' << array[i];
        }
        cout << '\n';
    }

    /**
     * @brief Sum array's elements
     *
     * @tparam type
     * @param array
     * @param size
     */
    template <typename type>
    void sum_array(type array[], int size)
    {
        int sum = 0;
        for (size_t i = 0; i < size; i++)
        {
            sum += array[i];
        }
        cout << "Sum = " << sum << '\n';
    }

    /**
     * @brief Product of array's elements
     *
     * @tparam type
     * @param array
     * @param size
     */
    template <typename type>
    void prod_array(type array[], int size)
    {
        int prod = 1;
        for (size_t i = 0; i < size; i++)
        {
            prod *= array[i];
        }
        cout << "Product = " << prod << '\n';
    }

    /**
     * @brief Average number of array's elements
     *
     * @tparam type
     * @param array
     * @param size
     */
    template <typename type>
    void avg_array(type array[], int size)
    {
        int sum = 0;
        for (size_t i = 0; i < size; i++)
        {
            sum += array[i];
        }
        cout << "Avg = " << sum / size << '\n';
    }

    /**
     * @brief Amount of array's elements in range
     *
     * @tparam type
     * @param array
     * @param size
     */
    template <typename type>
    void range_array(type array[], int size)
    {
        int from = 0;
        int to = 0;

        cout << "Range of array --- from 0 to " << size - 1 << '\n';
        cout << "Your range\nfrom: ";
        cin >> from;
        // Is out of range
        if (from >= size || from < 0)
        {
            cout << "\nOut of range\n";
        }
        // Continues
        else
        {
            cout << "to: ";
            cin >> to;
            // Is out of range
            if (to >= size || to < 0)
            {
                cout << "\nOut of range\n";
            }
            // Continues
            else
            {
                // Are equal
                if (from == to)
                {
                    cout << "\nThey are equal\n";
                }
                // Countinue
                else
                {
                    cout << "Amount of array's elements: " << to - from - 1 << '\n';
                    for (size_t i = from; i < to + 1; i++)
                    {
                        cout << ' ' << array[i];
                    }
                    cout << '\n';
                }
            }
        }
    }
};
