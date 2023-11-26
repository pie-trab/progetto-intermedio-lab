#include "../include/BookShelf.h"
#include "../include/Book.h"

#include <iostream>

constexpr int INIT_CAPACITY = 1;

BookShelf::BookShelf() : size{0}, capacity{INIT_CAPACITY}, buffer{new Book[INIT_CAPACITY]} {}

BookShelf::BookShelf(int n) : size{0}, capacity{n}, buffer{new Book[capacity]} {}

BookShelf::~BookShelf()
{
    delete[] buffer;
}

Book BookShelf::operator[](int i) const
{
    return buffer[i];
}

Book& BookShelf::operator[](int i)
{
    return buffer[i];
}

const Book& BookShelf::at(int i) const
{
    if (i >= 0 && i < size) {
        return buffer[i];
    }
    throw out_of_range();
}

Book& BookShelf::at(int i)
{
    if (i >= 0 && i < size) {
        return buffer[i];
    }
    throw out_of_range();
}

void BookShelf::reserve(int n)
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

void BookShelf::push_back(Book elem)
{
    if (size == capacity) {
        reserve(2 * capacity);
    }
    buffer[size] = elem;
    size++;
}

Book BookShelf::pop_back()
{
    if (size > 0) {
        size--;
        return buffer[size];
    }
    throw empty_vector();
}

BookShelf::BookShelf(const BookShelf& BookShelf) : size{BookShelf.size}, capacity{BookShelf.capacity}, buffer{new Book[BookShelf.size]}
{
    std::copy(BookShelf.buffer, BookShelf.buffer + size, buffer);
    std::cout << "costruttore di copia invocato\n";  // TODO
}

BookShelf& BookShelf::operator=(const BookShelf& BookShelf)
{
    Book* temp = new Book[BookShelf.size];
    std::copy(BookShelf.buffer, BookShelf.buffer + BookShelf.size, temp);
    delete[] buffer;
    buffer = temp;
    size = BookShelf.size;
    capacity = BookShelf.capacity;
    std::cout << "operatore di copia invocato\n";  // TODO
    return *this;
}

BookShelf::BookShelf(BookShelf&& BookShelf) : size{BookShelf.size}, capacity{BookShelf.capacity}, buffer{BookShelf.buffer}
{
    BookShelf.size = 0;
    BookShelf.capacity = INIT_CAPACITY;
    BookShelf.buffer = nullptr;
    std::cout << "costruttore di spostamento invocato\n";  // TODO
}

BookShelf& BookShelf::operator=(BookShelf&& BookShelf)
{
    delete[] buffer;
    size = BookShelf.size;
    capacity = BookShelf.capacity;
    buffer = BookShelf.buffer;
    BookShelf.size = 0;
    BookShelf.capacity = INIT_CAPACITY;
    BookShelf.buffer = nullptr;
    std::cout << "operatore di spostamento invocato\n";  // TODO
    return *this;
}

BookShelf::BookShelf(std::initializer_list<Book> lst) : size{(int)lst.size()}, capacity{(int)lst.size()}, buffer{new Book[size]}
{
    std::copy(lst.begin(), lst.end(), buffer);
}

int BookShelf::get_size() const
{
    return size;
}