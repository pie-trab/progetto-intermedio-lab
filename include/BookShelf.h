#ifndef BOOKSHELF_H
#define BOOKSHELF_H

#include "Book.h"

#include <string>

class BookShelf
{
private:
    int size;
    int capacity;
    Book* buffer;

    void reserve(int);

public:
    BookShelf();
    BookShelf(int);
    ~BookShelf();
    BookShelf(const BookShelf&);
    BookShelf(BookShelf&&);
    BookShelf(std::initializer_list<Book>);

    Book operator[](int) const;
    Book& operator[](int);
    const Book& at(int) const;
    Book& at(int);
    void push_back(Book);
    Book pop_back();
    BookShelf& operator=(const BookShelf&);
    BookShelf& operator=(BookShelf&&);
    int get_size() const;
};

// index out of range exception
class out_of_range
{
public:
    std::string get_message()
    {
        return "index out of range\n";
    }
};

//  empty vector exception
class empty_vector
{
public:
    std::string get_message()
    {
        return "empty vector\n";
    }
};
#endif