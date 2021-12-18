#include <iostream>

//-----------------------------------------------------------------------------------------------------

/**
Задание 1. Создайте структуру, описывающую комплексное 
число. Реализуйте арифметические операции с комплекс-
ными числами: сумму, разность, умножение, деление.
 */

// Создаем структуру комплексных чисел
struct complex_number{
    // Первое комплексное число - a
    double f_first_complex;
    // Первое комплексное число с мнимой единицей - b
    double f_second_complex;
    // Второе комплексное число - c
    double s_first_complex;
    // Второе комплексное число с мнимой единицей - d
    double s_second_complex;
};

/**
 * @brief 
 * 
 * @param number            структура комплексных чисел
 * @param f_first_complex   первое комплексное число - a
 * @param f_second_complex  первое комплексное число с мнимой единицей - b
 * @param s_first_complex   второе комплексное число - c
 * @param s_second_complex  второе комплексное число с мнимой единицей - d
 */
void initial(complex_number*& number,double f_first_complex,double f_second_complex,double s_first_complex,double s_second_complex){
    // Первое комплексное число
    number -> f_first_complex = f_first_complex;
    // Первое комплексное число с мнимой единицей 
    number -> f_second_complex = f_second_complex;
    // Второе комплексное число 
    number -> s_first_complex = s_first_complex;
    // Второе комплексное число с мнимой единицей 
    number -> s_second_complex = s_second_complex;
}

// СУММА -------------------------------------------
/**
 * @brief Сложение первых чисел(по подобным слагаемым)
 * 
 * @param number структура с комплексными числами
 */
double plus_first_complex(complex_number*& number){
    double result = 0;
    result = number->f_first_complex + number->s_first_complex; 
    return result;
}

/**
 * @brief Сложение вторых чисел с мнимым числом(по подобным слагаемым)
 * 
 * @param number структура с комплексными числами
 */
double plus_second_complex(complex_number*& number){
    double result = 0;
    result = number->f_second_complex + number->s_second_complex; 
    return result;
}

/**
 * @brief Вывод результата суммы 
 * 
 * @param number                 структура с комплесными числами
 * @param result_first_complex   сумма первых чисел
 * @param result_second_complex  сумма вторых чисел с мнимым числом 
 */
void print_sum(complex_number*& number,double result_first_complex,double result_second_complex){
    printf("(%.2f + %.2fi) + (%.2f + %.2fi) = %.2f + %.2fi\n",number->f_first_complex,number->f_second_complex,
    number->s_first_complex,number->s_second_complex,result_first_complex,result_second_complex);
}

// РАЗНОСТЬ -------------------------------------------
/**
 * @brief Разность вторых чисел с мнимым числом(по подобным слагаемым)
 * 
 * @param number структура с комплексными числами
 */
double minus_first_complex(complex_number*& number){
    double result = 0;
    result = number->f_first_complex - number->s_first_complex; 
    return result;
}

/**
 * @brief Разность вторых чисел с мнимым числом(по подобным слагаемым)
 * 
 * @param number структура с комплексными числами
 */
double minus_second_complex(complex_number*& number){
    double result = 0;
    result = number->f_second_complex - number->s_second_complex; 
    return result;
}

/**
 * @brief Вывод результата разности
 * 
 * @param number                 структура с комплесными числами
 * @param result_first_complex   разница первых чисел
 * @param result_second_complex  разница вторых чисел с мнимым числом 
 */
void print_difference(complex_number*& number,double result_first_complex,double result_second_complex){
    printf("(%.2f + %.2fi) - (%.2f + %.2fi) = %.2f + %.2fi\n",number->f_first_complex,number->f_second_complex,
    number->s_first_complex,number->s_second_complex,result_first_complex,result_second_complex);
}

// УМНОЖЕНИЕ -------------------------------------------
/**
 * @brief Умножение первой части (ac - bd) 
 * 
 * @param number структура с комплексными числами
 */
double multi_first_complex(complex_number*& number){
    // Результат умножения
    double result = 0;
    // (ac - bd) 
    result = (number->f_first_complex * number->s_first_complex) - (number->f_second_complex * number->s_second_complex); 
    return result;
}

/**
 * @brief Умножение второй части (bc + ad)i
 * 
 * @param number структура с комплексными числами
 */
double multi_second_complex(complex_number*& number){
    // Результат умножения
    double result = 0;
    // (bc + ad)i
    result = (number->f_second_complex * number->s_first_complex) + (number->f_first_complex * number->s_second_complex); 
    return result;
}

/**
 * @brief Вывод результата умножения
 * 
 * @param number                 структура с комплесными числами
 * @param result_first_complex   умножение первой части
 * @param result_second_complex  умножение второй части
 */
void print_multi(complex_number*& number,double result_first_complex,double result_second_complex){
    printf("(%.2f + %.2fi) * (%.2f + %.2fi) = %.2f + %.2fi\n",number->f_first_complex,number->f_second_complex,
    number->s_first_complex,number->s_second_complex,result_first_complex,result_second_complex);
}

// ДЕЛЕНИЕ -------------------------------------------
/**
 * @brief Деление первой части (ac - bd) 
 * 
 * @param number структура с комплексными числами
 */
double div_first_complex(complex_number*& number){
    // Результат умножения
    double result = 0;
    // (ac - bd) 
    result = (number->f_first_complex * number->s_first_complex) - (number->f_second_complex * number->s_second_complex)
    // (c^2 + d^2)
     / ( (number->s_first_complex * number->s_first_complex) +(number->s_second_complex * number->s_second_complex) ); 
    return result;
}

/**
 * @brief Деление второй части (bc + ad) / (c^2 + d^2) * i
 * 
 * @param number структура с комплексными числами
 */
double div_second_complex(complex_number*& number){
    // Результат умножения
    double result = 0;
    // (bc + ad)
    result = ((number->f_second_complex * number->s_first_complex) + (number->f_first_complex * number->s_second_complex))
    // (c^2 + d^2)
     / ( (number->s_first_complex * number->s_first_complex) +(number->s_second_complex * number->s_second_complex) ); 
    return result;
}

/**
 * @brief Вывод результата деления
 * 
 * @param number                 структура с комплесными числами
 * @param result_first_complex   деление первой части
 * @param result_second_complex  деление второй части
 */
void print_div(complex_number*& number,double result_first_complex,double result_second_complex){
    printf("(%.2f + %.2fi) / (%.2f + %.2fi) = %.2f + %.2fi\n",number->f_first_complex,number->f_second_complex,
    number->s_first_complex,number->s_second_complex,result_first_complex,result_second_complex);
}

//-----------------------------------------------------------------------------------------------------

/**
Задание 2. Реализовать структуру «Автомобиль» (длина, 
клиренс (высота посадки), объем двигателя, мощность 
двигателя, диаметр колес, цвет, тип коробки передач). 
Создайте функции для задания значений, отображения 
значений, поиска значений.
*/

// Структура автомобиль
struct automobile{
    // Длина авто
    double length ;
    // Клиренс
    double clearance;
    // Объем двигателя
    double engine_displacement;
    // Мощность двигателя
    double engine_power;
    // Диаметр колес
    double wheel_diameter;
    // Цвет
    std::string color;
    // Тип коробки передач
    std::string gearbox_type;
};

/**
 * @brief Данные об автомобиле
 * 
 * @param info структура данных об автомобиле
 */
void init_struct(automobile*& info){
    info -> length = 4.8;
    info -> clearance = 16.5;
    info -> engine_displacement = 2488;
    info -> engine_power = 194;
    info -> wheel_diameter = 70.5;
    info -> color = "Red";
    info -> gearbox_type = "Automatic";
}

/**
 * @brief Вывод данных об автомобиле
 * 
 * @param info структура данных об автомобиле
 */
void print_struct(automobile*& info){
    printf("Car info\n\nLength,cm: %.1f\nClearance,cm: %.1f\nEngine displacement,cm^3: %.1f\n",info -> length,info->clearance,info->engine_displacement);
    printf("Engine power,h.p.: %.1f\nWheel diametr: %.1f\n",info -> engine_power,info->wheel_diameter);
    std::cout<< "Color: " << info->color << "\n";
    std::cout<< "Gearbox type: " << info->gearbox_type << "\n";
}

int main(){
    /* 1 */
    // complex_number* numbers = new complex_number;
    // initial(numbers,2,5,4,2);
    // // Сумма
    // double result_first_complex = plus_first_complex(numbers);
    // double result_second_complex = plus_second_complex(numbers);
    // print_sum(numbers,result_first_complex,result_second_complex);
    // // Разность
    // result_first_complex = minus_first_complex(numbers);
    // result_second_complex = minus_second_complex(numbers);
    // print_difference(numbers,result_first_complex,result_second_complex);
    // // Умножение
    // result_first_complex = multi_first_complex(numbers);
    // result_second_complex = multi_second_complex(numbers);
    // print_multi(numbers,result_first_complex,result_second_complex);
    // // Деление
    // result_first_complex = div_first_complex(numbers);
    // result_second_complex = div_second_complex(numbers);
    // print_div(numbers,result_first_complex,result_second_complex);
    // delete numbers;
    /* 2 */
    // automobile* info = new automobile;
    // init_struct(info);
    // print_struct(info);
    // delete info;

    return 0;
}