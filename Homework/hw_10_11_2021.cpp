#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string.h>

/**
Разработайте программу «Библиотека». Соз-
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


/**
 * @brief Создаем структуру "Книга"
 * 
 */
struct book{
    // Название книги
    char name;
    // Автор книги
    char author;
    // Издательство
    char publisher;
    // Жанр книги 
    char genre;
};

book add_book(const char* name,const char* author,const char* publisher,const char* genre){
    book res;
	res.name = new char[strlen(name) + 1];
	strcpy(res.name, name);
	res.author = new char[strlen(author) + 1];
	strcpy(res.author, author);
    
	return res;
}


std::ostream& operator << (std::ostream& stream, const book& p) {
	return stream << "[ " << p.name << " - " << p.author << " - " << p.genre << " - " << p.publisher << " ]";
}

int main(){
    book* library = new book[10];
    library[0] = add_book("Name","Author","Publisher","Genre");

    return 0;
}