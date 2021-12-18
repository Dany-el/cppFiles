// hw_9_11_2021.cpp : 

/*
Задание 1. Разработайте программу «Библиотека». Соз-
дайте структуру «Книга» (название, автор, издательство,
жанр). Создайте массив из 10 книг. Реализуйте для него
следующие возможности:
 ■ Редактировать книгу;
 ■ Печать всех книг;
 ■ Поиск книг по автору;
 ■ Поиск книги по названию;
 ■ Сортировка массива по названию книг;
 ■ Сортировка массива по автору;
 ■ Сортировка массива по издательству.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <conio.h>

/*
Структура с данными о книге
- Имя
- Автор
- Жанр
- Издатель
*/
struct book {
    // Название
    char* name;
    // Автор
    char* author;
    // Жанр
    char* genre;
    // Издатель
    char* publisher;
};

/*
* Константное значение:
Количество книг
которое может ввести пользователь
*/
const int COUNT_BOOK = 10;

/*
* Общая переменная:
Название книги
(вводит пользователь)
*/
char* name_p = new char[100];

/*
* Общая переменная:
Автор 
(вводит пользователь)
*/ 
char* author_p = new char[100];

/*
* Общая переменная:
Жанр
(вводит пользователь)
*/
char* genre_p = new char[100];

/*
* Общая переменная:
Издатель
(вводит пользователь)
*/
char* publisher_p = new char[100];

/*
Счетчик для:
Количество введных
книг пользователем
*/
int count_input_book = 0;



// Библиотека 
book* library = new book[COUNT_BOOK];


/*
* Добавляем книгу в структуру
* 
@param name      - название книги
@param author    - автор книги
@param genre     - жанр книги
@param publisher - издатель книги

@return Структуру с добавленной книгой
*/
book add_book(const char* name,const char* author,const char* genre,const char* publisher) {
    // Объявляем структуру
    // где будут хранится данные о книге
    book library;  // Структура для данных о книге 

    // Добавляем имя в структуру
    library.name = new char[strlen(name) + 1];
    strcpy(library.name, name);
    
    // Добавляем автора в структуру
    library.author = new char[strlen(author) + 1];
    strcpy(library.author, author);
    
    // Добавляем жанр в структуру
    library.genre = new char[strlen(genre) + 1];
    strcpy(library.genre, genre);

    // Добавляем издателя в структуру
    library.publisher = new char[strlen(publisher) + 1];
    strcpy(library.publisher, publisher);
    
    // Возвращаем новую структуру 
    // с добавленной информацией о книге
    return library;
}

/*
Удобный вывод для структуры "Книга"

@param p - структура "Книга" 
*/
std::ostream& operator << (std::ostream& stream, const book& p) {
    return stream << "Name:     \"" << p.name
                  << "\"\n  Author:    " << p.author
                  << "\n  Genre:     " << p.genre
                  << "\n  Publisher: " << p.publisher
                  << "\n--------------------------------------------\n";
}

/*
Вывод библиотеки
*/ 
void print_book() {
    for (size_t i = 0; i < count_input_book; i++)
    {
        // Вывод 1,2,3 ...
        std::cout << i + 1 << ".";
        // Выводим библиотеку
        std::cout << library[i];
    }
    if(count_input_book == 0){
        std::cout<<"Library is empty";
    }
}

/*
Изменяем информацию о книге
с выбором
-Имя
-Автор
-Жанр
-Издатель
*/
void change_info() {
    std::cout << "What book would you like to edit ?\n\n";
    // Выводим количество книг, которые есть в библиотеке
    print_book();
    // Пользователь нажимает на клавишу(1 - count_input_book)
    int choise_book_number = _getch() - '0';  // Код кнопки клавиатуры / номер книги в библиотеке
    // Если это число от 1 до количества введенных книг
    if (choise_book_number < count_input_book + 1) {
        // Выводим меню, где
        // даем выбор пользователю
        std::cout << "Edit info:\n1.Name\n2.Author\n3.Genre\n4.Publisher\n";
        // Пользователь нажимает на клавишу(1-4) 
        int choise_edit_info = _getch() - '0';
        // Проверяем, какой сделал выбор пользователь
        switch (choise_edit_info) {
        // Изменяем имя книги
        case 1:
            std::cout << "\nNew book`s name --> ";
            // Пользователь вводит новое имя 
            gets_s(name_p, 100);
            // Записываем новое имя 
            // на место заменяемого 
            // в книге, номер которой выбрал пользователь
            strcpy(library[choise_book_number - 1].name, name_p);
            break;
        // Изменяем автора книги
        case 2:
            std::cout << "\nNew book`s author --> ";
            // Пользователь вводит нового автора
            gets_s(author_p, 100);
            // Записываем нового автора
            // на место заменяемого 
            // в книге, номер которой выбрал пользователь
            strcpy(library[choise_book_number - 1].author, author_p);
            break;
        // Изменяем жанр книги
        case 3:
            std::cout << "\nNew book`s genre --> ";
            // Пользователь вводит новый жанр
            gets_s(genre_p, 100);
            // Записываем новый жанр
            // на место заменяемого  
            // в книге, номер которой выбрал пользователь
            strcpy(library[choise_book_number - 1].genre, genre_p);
            break;
        // Изменяем издателя книги
        case 4:
            std::cout << "\nNew book`s publisher --> ";
            // Пользователь вводи нового издателя 
            gets_s(publisher_p, 100);
            // Записываем нового издателя
            // на место заменяемого
            // в книге, номер которой выбрал пользователь
            strcpy(library[choise_book_number - 1].publisher, publisher_p);
            break;
        }
    }
    // Если книг нет или же неверный номер книги
    else {
        std::cout << "\nWrong number or library is empty\n";
    }
}

/*
Поиск по имени книги
*/
void search_by_name() {
    // Найдена/не найдена книга
    bool is_find = false;
    std::cout << "\nBook`s name --> ";
    // Пользователь вводит название книги
    // которое нужно найти в библиотеке
    gets_s(name_p, 100);
    // Поиск
    for (size_t i = 0; i < count_input_book; i++)
    {
        // Если книга найдена
        // возвращает адрес первого символа
        if (strstr(library[i].name,name_p) != NULL) {
            std::cout << i << ".";
            // Выводим информацию о книге
            // которая нужна пользователю
            std::cout << library[i] << "\n";
            // Книга найдена 
            is_find = true;
            // Завершаем поиск
            break;
        }
    }
    // Если книга не найдена с таким именем
    if(!is_find){
        std::cout<< "\nName not found";
    }
}

/*

*/
void search_by_author() {
    // Найдена/не найдена книга
    bool is_find = false;
    std::cout << "\nBook`s author --> ";
    // Пользователь вводит автора
    // которое нужно найти в библиотеке
    gets_s(author_p, 100);
    // Поиск автора в библиотеке
    for (size_t i = 0; i < count_input_book; i++)
    {
        // Если книга найдена
        // возвращает адрес первого символа
        if (strstr(library[i].author, author_p) != NULL) {
            std::cout << i << ".";
            // Выводим информацию о книге
            // которая нужна пользователю
            std::cout << library[i] << "\n";
            // Книга найдена 
            is_find = true;
            break;
        }
    }
    // Если книга не найдена с таким автором
    if(!is_find){
        std::cout<< "\nAuthor not found";
    }
}

/*
Сортировка названий книг по алфавиту 
*/
void filter_name() {
    // Временное хранилище книги 
    book tmp;
    // Сортировка
    for (size_t i = 0; i < count_input_book; i++)
    {
        for (size_t j = 0; j < count_input_book; j++)
        {
            // Проверяем 1 буквы названий книг
            // Возвращает 1 - library[i].name > library[j].name
            // Возвращает 0 - library[i].name = library[j].name
            // Возвращает -1 - library[i].name < library[j].name
            int value = _stricmp(library[i].name, library[j].name);
            // Если library[i].name < library[j].name
            if (value < 0) {
                // Записываем в хранилище книгу,
                // у которой 1 буква название книги меньше по алфавиту
                tmp = library[i];
                // Меняем library[j] на library[i]
                library[i] = library[j];
                library[j] = tmp;
            }
        }
    }
    // Выводим измененный массив
    print_book();
}

/*
Сортировка авторов по алфавиту
*/
void filter_author() {
    // Временное хранилище книги
    book tmp;
    // Сортировка
    for (size_t i = 0; i < count_input_book; i++)
    {
        for (size_t j = 0; j < count_input_book; j++)
        {
            // Проверяем 1 буквы авторов
            // Возвращает 1 - library[i].name > library[j].name
            // Возвращает 0 - library[i].name = library[j].name
            // Возвращает -1 - library[i].name < library[j].name
            int value = _stricmp(library[i].author, library[j].author);
            // Если library[i].author < library[j].author
            if (value < 0) {
                // Записываем в хранилище книгу,
                // у которой 1 буква автора книги меньше по алфавиту
                tmp = library[i];
                // Меняем library[j] на library[i]
                library[i] = library[j];
                library[j] = tmp;
            }
        }
    }
    // Выводим измененный массив
    print_book();
}

/*
Сортировка издателей по алфавиту
*/
void filter_publisher() {
    // Временное хранилище книги
    book tmp;
    // Сортировка
    for (size_t i = 0; i < count_input_book; i++)
    {
        for (size_t j = 0; j < count_input_book; j++)
        {
            // Проверяем 1 буквы издателей
            // Возвращает 1 - library[i].name > library[j].name
            // Возвращает 0 - library[i].name = library[j].name
            // Возвращает -1 - library[i].name < library[j].name
            int value = _stricmp(library[i].publisher, library[j].publisher);
            // Если library[i].publisher < library[j].publisher
            if (value < 0) {
                // Записываем в хранилище книгу,
                // у которой 1 буква издателя книги меньше по алфавиту
                tmp = library[i];
                // Меняем library[j] на library[i]
                library[i] = library[j];
                library[j] = tmp;
            }
        }
    }
    // Выводим измененный массив
    print_book();
}

/*
Вводим информацию о книге 
*/
void input_book() {
    printf("\n*********\nBook info\n");
    // Пользователь вводит название книги
    std::cout << "Book`s name --> ";
    gets_s(name_p, 100);
    // Пользователь вводит автора книги
    std::cout << "\nBook`s author --> ";
    gets_s(author_p, 100);
    // Пользователь вводит жанр книги
    std::cout << "\nBook`s genre --> ";
    gets_s(genre_p, 100);
    // Пользователь вводит издателя книги
    std::cout << "\nBook`s publisher --> ";
    gets_s(publisher_p, 100);
}

/*
Меню выбора для пользователя
*/
void menu_choise() {
    printf("Menu:\n1.Edit book info\n2.Print all books\n");
    printf("3.Search book by name\n4.Search book by author\n");
    printf("5.Sort by name\n6.Sort by author\n7.Sort by publisher\n8.Add book info\n\nEsc to exit\n");
}

/*
Работа меню
*/
void main_menu() {
    int choise = 0;
    do {
        system("cls");
        menu_choise();
        choise = _getch();
        switch (choise - '0') {
        // Редактируем информацию о книге
        case 1:
            system("cls");
            change_info();
            std::cout << "\npress A key";
            choise = _getch();
            break;
        // Вывод библиотеки
        case 2:
            system("cls");
            print_book();
            std::cout << "\npress A key";
            choise = _getch();
            break;
        // Поиск по имени
        case 3:
            system("cls");
            search_by_name();
            std::cout << "\npress A key";
            choise = _getch();
            break;
        // Поиск по фамилии
        case 4:
            system("cls");
            search_by_author();
            std::cout << "\npress A key";
            choise = _getch();
            break;
        // Сортировка по имени 
        case 5:
            system("cls");
            filter_name();
            std::cout << "\npress A key";
            choise = _getch();
            break; 
        // Сортировка по фамилии
        case 6:
            system("cls");
            filter_author();
            std::cout << "\npress A key";
            choise = _getch();
            break;
        // Сортировка по издательству
        case 7:
            system("cls");
            filter_publisher();
            std::cout << "\npress A key";
            choise = _getch();
            break;
        // Ввод данных о книге
        case 8:
            system("cls");
            input_book();
            library[count_input_book] = add_book(name_p, author_p, genre_p, publisher_p);
            count_input_book++;
            std::cout << "\npress A key";
            choise = _getch();
            break;
        }
    } while (choise != 27); // Пока не будет нажата кнопка "Esc"
}

int main()
{
    main_menu();

    delete name_p;
    delete author_p;
    delete genre_p;
    delete publisher_p;
    delete[] library;
    return 0;
}