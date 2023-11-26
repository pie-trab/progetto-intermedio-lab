#include "../include/MyVector.h"
#include "../include/Book.h"

#include <iostream>

constexpr int INIT_CAPACITY = 1;

MyVector::MyVector() : size{0}, capacity{INIT_CAPACITY}, buffer{new Book[INIT_CAPACITY]} {}

MyVector::MyVector(int n) : size{0}, capacity{n}, buffer{new Book[capacity]} {}

MyVector::~MyVector()
{
    delete[] buffer;
}

Book MyVector::operator[](int i) const
{
    return buffer[i];
}

Book& MyVector::operator[](int i)
{
    return buffer[i];
}

const Book& MyVector::at(int i) const
{
    if (i >= 0 && i < size) {
        return buffer[i];
    }
    throw out_of_range();
}

Book& MyVector::at(int i)
{
    if (i >= 0 && i < size) {
        return buffer[i];
    }
    throw out_of_range();
}

void MyVector::reserve(int n)
{
    if (n > capacity) {
        Book* temp = new Book[n];
        for (int i = 0; i < size; i++) {
            temp[i] = buffer[i];
        }
        delete[] buffer;
        buffer = temp;
        capacity = n;
    }
}

void MyVector::push_back(Book elem)
{
    if (size == capacity) {
        reserve(2 * capacity);
    }
    buffer[size] = elem;
    size++;
}

Book MyVector::pop_back()
{
    if (size > 0) {
        size--;
        return buffer[size];
    }
    throw empty_vector();
}

MyVector::MyVector(const MyVector& myVector) : size{myVector.size}, capacity{myVector.capacity}, buffer{new Book[myVector.size]}
{
    std::copy(myVector.buffer, myVector.buffer + size, buffer);
    std::cout << "costruttore di copia invocato\n";  // TODO
}

MyVector& MyVector::operator=(const MyVector& myVector)
{
    Book* temp = new Book[myVector.size];
    std::copy(myVector.buffer, myVector.buffer + myVector.size, temp);
    delete[] buffer;
    buffer = temp;
    size = myVector.size;
    capacity = myVector.capacity;
    std::cout << "operatore di copia invocato\n";  // TODO
    return *this;
}

MyVector::MyVector(MyVector&& myVector) : size{myVector.size}, capacity{myVector.capacity}, buffer{myVector.buffer}
{
    myVector.size = 0;
    myVector.capacity = INIT_CAPACITY;
    myVector.buffer = nullptr;

    std::cout << "costruttore di spostamento invocato\n";  // TODO
}

MyVector& MyVector::operator=(MyVector&& myVector)
{
    delete[] buffer;
    size = myVector.size;
    capacity = myVector.capacity;
    buffer = myVector.buffer;
    myVector.size = 0;
    myVector.capacity = INIT_CAPACITY;
    myVector.buffer = nullptr;
    std::cout << "operatore di spostamento invocato\n";  // TODO
    return *this;
}

MyVector::MyVector(std::initializer_list<Book> lst) : size{(int)lst.size()}, capacity{(int)lst.size()}, buffer{new Book[size]}
{
    std::copy(lst.begin(), lst.end(), buffer);
}
