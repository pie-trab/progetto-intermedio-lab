#ifndef MYVECTOR_H
#define MYVECTOR_H

#include <string>

#include "Book.h"

class MyVector
{
private:
    int size;
    int capacity;
    Book* buffer;

    void reserve(int);

public:
    MyVector();
    MyVector(int);
    ~MyVector();
    MyVector(const MyVector&);
    MyVector(MyVector&&);
    MyVector(std::initializer_list<Book>);

    Book operator[](int) const;
    Book& operator[](int);
    const Book& at(int) const;
    Book& at(int);
    void push_back(Book);
    Book pop_back();
    MyVector& operator=(const MyVector&);
    MyVector& operator=(MyVector&&);
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