#include "Price.h"
#include <iostream>

/*
 * �������� �������

 @param p_width  - ������ �������
 @param p_length - ����� �������

 @return int - �������� �������
*/
int Perimeter_Room(int p_width,int p_length){
	return 2*(p_width+p_length);
}

/*
* ������� �������
*
* @param perimeter - �������� �������
* @param p_height  - ������ �������
*
* @return int - �������
*/
int Area_Room(int perimeter,int p_heigth){
	return perimeter * p_heigth;
}

/**
 * @brief ����� ��������
 * 
 * @param area - ������� �������
 * @param sum  - ���������� ��� ����� ��������
 * @return int - ����� ��������
 */
int Sum_of_areas(int area,int sum){
    sum += area;
    return sum;
}

/**
 * @brief ���������� ������� ��� �������
 * 
 * @param sum_of_areas - ����� �������� ���� ������
 * @param area_of_roll - ������� ������
 * @return int - ���������� �������
 */
int Rolls_amount(int sum_of_areas,int area_of_roll){
    int tmp = sum_of_areas/area_of_roll;
    if((double)sum_of_areas/area_of_roll > tmp){
        tmp++;
    }
    return tmp;
}