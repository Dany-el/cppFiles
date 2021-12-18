
#include <iostream>
#include <random>
#include <iomanip>

typedef int** datapoint;
typedef int database;

// Размер массива
const int SIZE = 5;

//--------------------------------------------------------------------

/*
Задание 1. Написать функцию, добавляющую столбец
двухмерному массиву в указанную позицию.
*/
/*
@param arr   - многомерный массив
@param index - индекс, который задает пользователь
@param size  - размер массива
*/
void addColumn(datapoint arr, int index, int size) {
   // Проверяем,если число пользователя нам подходит 
   if (index > SIZE || index < 0) return;
   // Строки
   for (size_t i = 0; i < size; i++) {
       // Создаем новый двумерный массив        
       database* newRow = new database[size + 1];  // Двумерный массив с +1 столбцом
       database k = 0;  // Счетчик для записи нуля в столбец
       // Столбцы
       for (size_t j = 0; j < size; j++) {
           // Если счетчик столбца равен индексу пользователя
           if (j == index) {
               // Записываем в двумерный массив(столбец пользователя) "0"
               newRow[k] = 0;
               // +1
               k++;
           }
           // Записываем в новый массив значения первого многомерного массива
           newRow[k] = arr[i][j];
           // +1
           k++;
       }
       // Удаляем строку
       delete[] arr[i];
       // Перезаписываем с новыми значениями
       arr[i] = newRow;
   }
}

// Создание двумерного массива
datapoint makeArr() {
   datapoint arr = new int* [SIZE];
   for (size_t i = 0; i < SIZE; i++)
   {
       arr[i] = new int[SIZE];
   }
   return arr;
}

// Инициализация двумерного массива
void initArr(datapoint arr) {
   for (size_t i = 0; i < SIZE; i++)
   {
       for (size_t j = 0; j < SIZE; j++)
       {
           // 1-25
           arr[i][j] = i * SIZE + j + 1;
       }
   }
}

// Вывод массива
/*
@param arr - многомерный массив
@param size - константа SIZE
*/
void printArr(datapoint arr, int size) {
   for (size_t i = 0; i < SIZE; i++)
   {
       for (size_t j = 0; j < size; j++)
       {
           std::cout <<std::setw(4)<<arr[i][j] << " ";
       }
       std::cout << std::endl;
   }
}

//--------------------------------------------------------------------

/*
Задание 2. Написать функцию, удаляющую столбец двух-
мерного массива по указанному номеру.
*/
/*
@param arr - многомерный массив
@param index - индекс столбца пользователя
@param size - константа SIZE
*/
void removeColumn(datapoint arr, int index, int size) {
   // Проверяем,если число пользователя нам подходит 
   if (index > SIZE || index < 0) return;
   // Строки
   for (size_t i = 0; i < size; i++) {
       // Создаем новый двумерный массив        
       int* newRow = new database[size-1];  // Двумерный массив с -1 столбцом
       database k = 0;                      // Счетчик для записи нуля в столбец
       // Столбцы
       for (size_t j = 0; j < size; j++) {
           // Если счетчик столбца равен индексу пользователя
           if (j != index) {
               // Записываем в двумерный массив значения первого многомерного массива
               newRow[k] = arr[i][j];
               // +1
               k++;
           }
       }
       // Удаляем строку
       delete[] arr[i];
       // Перезаписываем с новыми значениями
       arr[i] = newRow;
   }
}


//--------------------------------------------------------------------

/*
Задание 3. Дана матрица порядка M×N (M строк, N столб-
цов). Необходимо заполнить ее значениями и написать
функцию, осуществляющую циклический сдвиг строк
и/или столбцов массива указанное количество раз и в ука-
занную сторону.
*/

// Значения двумерного массива(строки)
int* tmpRows;
/*
Смещение строк вверх
*/ 
/*
@param arr - многомерный массив
*/
void changeRowsUP(datapoint arr) {
   // Строки
   for (size_t row = 0; row < SIZE; row++)
   {       
       // Если это первая строка
       if (row == 0) {
            // Записываем строку
            tmpRows = arr[row];           
       }
       // Если это последняя строка
       if ((SIZE - 1) == row) {
           // Меняем первую и последнюю строку
           arr[SIZE - 1] = tmpRows;
       }
       // Иначе
       else {
           // Меняем строки
           arr[row] = arr[row + 1];
       }
   }
}

/*
Смещение строк вниз
*/ 
/*
@param arr - многомерный массив
*/
void change_rows_down(datapoint arr) {
   // Строки
   for (int row = SIZE - 1; row >= 0 ; row--)
   {
       // Если это не первая и не последняя строка
       if (0 != row || (SIZE - 1) != row) {
           // Меняем строки
           arr[row + 1] = arr[row];
       }
       // Если это последняя строка
       if ((SIZE - 1) == row) {
           // Записываем строку
           tmpRows = arr[row];
       }
       // Если это первая строка
       if (0 == row) {
           // Меняем первую и последнюю строку
           arr[0] = tmpRows;
       }        
   }
}

// Значения двумерного массива(столбцы)
int tmpCol;
/*
Смещение столбцов вправо
*/ 
/*
@param arr - многомерный массив
*/
void changeColumnsRIGHT(datapoint arr) {
   // Строки
   for (int i = 0; i < SIZE; i++)
   {
       // Столбцы
       for (int j = 0; j < SIZE; j++)
       {            
           // Если это 1 столбец
           if (j == 0) {
               // Записываем значения столбца
               tmpCol = arr[i][j];
           }
           // Если это последний столбец
           if ((SIZE - 1) == j) {
               // Меняем с 1 столбцом
               arr[i][SIZE - 1] = tmpCol;
           }
           // Иначе
           else {
               // Меняем столбцы
               arr[i][j] = arr[i][j + 1];
           }
       }
   }
}

/*
Смещение столбцов влево
*/ 
/*
@param arr - многомерный массив
*/
void change_columns_left(datapoint arr) {
   // Строки
   for (int i = SIZE - 1; i >= 0; i--) {
       // Столбцы
       for (int j = SIZE - 1; j >= 0; j--)
       {
           // Если это не 1 и не последний столбцы
           if (0 != j || (SIZE - 1) != j) {
               // Меняем местами
               arr[i][j + 1] = arr[i][j];
           }
           // Если это последний столбец
           if ((SIZE - 1) == j) {
               // Записываем значения столбца
               tmpCol = arr[i][j];
           }
           // Если это первый столец
           if (0 == j) {
               // Меняем с последним столбцом
               arr[i][0] = tmpCol;
           }
       }
   }        
}

/*
Пользователь выбирает смещение строки/столбца  
- Строки - вверх/вниз  
- Столбца - влево/вправо
*/
/*
@param arr - многомерный массив
@param choise - выбор пользователя
@param amount - количество повторений
*/
void move_to(datapoint arr,int choise,int amount) {
   // Выбор пользователя
   switch (choise) {
   // СТРОКА ---------------------------------
   // Строка вверх
   case 1:
       // Повторяем заданное пользователем раз
       for (size_t i = 0; i < amount; i++)
       {
           changeRowsUP(arr);
       }
       break;
   // Строка вниз
   case 2:
       // Повторяем заданное пользователем раз
       for (size_t i = 0; i < amount; i++)
       {
           change_rows_down(arr);
       }
       break;
   // СТОЛБЕЦ --------------------------------
   // Столбец влево
   case 3:
       // Повторяем заданное пользователем раз
       for (size_t i = 0; i < amount; i++)
       {
           changeColumnsRIGHT(arr); 
       }
       break;
   // Столбец вправо
   case 4:
       // Повторяем заданное пользователем раз
       for (size_t i = 0; i < amount; i++)
       {
           change_columns_left(arr);           
       }
       break;
   }    
}

// Вывод массива
void print_new_array(datapoint arr) {
   for (int i = 0; i < SIZE; i++)
   {
       for (int j = 0; j < SIZE; j++)
       {
           if ((SIZE-1) == j) {
               std::cout << std::setw(4) << arr[i][j] << std::endl;
           }            
           else {
               std::cout << std::setw(4) << arr[i][j];
           }
       }
   }
}

int main() {
    srand(time(NULL));

    datapoint arr = makeArr();
    int size = SIZE;
    initArr(arr);
    
    /* 1 */
    /*addColumn(arr, 4, size);
    size++;
    printArr(arr, size);
    std::cout << std::endl;
    delete[] arr;*/

    /* 2 */
    /*size = SIZE;
    printArr(arr, size);
    std::cout << std::endl;
    removeColumn(arr, 3, size);
    size--;
    printArr(arr, size);
    delete[] arr;*/

    /* 3 */
    // printArr(arr,SIZE);
    // move_to(arr, 1, 2);
    // std::cout << std::endl;
    // print_new_array(arr);
    return 0;
}