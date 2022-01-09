#include "Price.h"
#include <iostream>

/*
 * Периметр комнаты

 @param p_width  - ширина комнаты
 @param p_length - длина комнаты

 @return int - Периметр комнаты
*/
int Perimeter_Room(int p_width,int p_length){
	return 2*(p_width+p_length);
}

/*
* Площадь комнаты
*
* @param perimeter - периметр комнаты
* @param p_height  - высота комнаты
*
* @return int - Площадь
*/
int Area_Room(int perimeter,int p_heigth){
	return perimeter * p_heigth;
}

/**
 * @brief Сумма площадей
 * 
 * @param area - площадь комнаты
 * @param sum  - переменная для сбора площадей
 * @return int - Сумма площадей
 */
int Sum_of_areas(int area,int sum){
    sum += area;
    return sum;
}

/**
 * @brief Количество рулонов для покупки
 * 
 * @param sum_of_areas - сумма площадей всех комнат
 * @param area_of_roll - площадь рулона
 * @return int - Количество рулонов
 */
int Rolls_amount(int sum_of_areas,int area_of_roll){
    int tmp = sum_of_areas/area_of_roll;
    if((double)sum_of_areas/area_of_roll > tmp){
        tmp++;
    }
    return tmp;
}