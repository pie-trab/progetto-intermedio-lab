#ifndef BOOKSHELF_H
#define BOOKSHELF_H

#include "Book.h"

class BookShelf
{
private:
    int size;       // number of books
    int capacity;   // capacity of the buffer
    Book* buffer;

    void reserve(int);  // reserves memory for the buffer

public:
    BookShelf();
    BookShelf(int);
    ~BookShelf();
    BookShelf(const BookShelf&);            // copy constructor
    BookShelf(BookShelf&&);                 // move constructor
    BookShelf(std::initializer_list<Book>); // constructor with initializer list

    const Book& operator[](int) const;
    Book& operator[](int);
    const Book& at(int) const;
    Book& at(int);
    void push_back(Book);
    const Book& pop_back();
    BookShelf& operator=(const BookShelf&); // copy operator
    BookShelf& operator=(BookShelf&&);      // move operator
    int get_size() const;
};

#endif