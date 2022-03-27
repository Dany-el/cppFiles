#pragma once
#include <iostream>

using std::cout;

struct B_function
{
    /**
     * @brief Sum
     *
     * @tparam type
     * @param f_par - first parameter
     * @param s_par - second parameter
     */
    template <typename type>
    void sum(type f_par, type s_par)
    {
        cout << f_par << " + " << s_par << " = " << f_par + s_par << '\n';
    }

    /**
     * @brief Difference
     *
     * @tparam type
     * @param f_par - first parameter
     * @param s_par - second parameter
     */
    template <typename type>
    void diff(type f_par, type s_par)
    {
        cout << f_par << " - " << s_par << " = " << f_par - s_par << '\n';
    }

    /**
     * @brief Product
     *
     * @tparam type
     * @param f_par - first parameter
     * @param s_par - second parameter
     */
    template <typename type>
    void product(type f_par, type s_par)
    {
        cout << f_par << " * " << s_par << " = " << f_par * s_par << '\n';
    }
};
