#include "../include/BookShelf.h"
#include "../include/Book.h"

#include <iostream>

constexpr int INIT_CAPACITY = 1;

/**
 * @brief Construct a new Book Shelf:: Book Shelf object
 *
 */
BookShelf::BookShelf() : size{0}, capacity{INIT_CAPACITY}, buffer{new Book[INIT_CAPACITY]} {}

/**
 * @brief Construct a new Book Shelf:: Book Shelf object
 *
 * @param n numbers of book to initialize the bookshelf with
 */
BookShelf::BookShelf(int n) : size{0}, capacity{n}, buffer{new Book[capacity]} {}

/**
 * @brief Destroy the Book Shelf:: Book Shelf object
 *
 */
BookShelf::~BookShelf()
{
    delete[] buffer;
}

/**
 * @brief Initializer list construct a new Book Shelf:: Book Shelf object
 *
 * @param lst lists of books
 */
BookShelf::BookShelf(std::initializer_list<Book> lst) : size{(int)lst.size()}, capacity{(int)lst.size()}, buffer{new Book[size]}
{
    std::copy(lst.begin(), lst.end(), buffer);
}

/**
 * @brief Copy construct of Book Shelf:: Book Shelf object
 *
 * @param BookShelf Object to copy
 */
BookShelf::BookShelf(const BookShelf& BookShelf) : size{BookShelf.size}, capacity{BookShelf.capacity}, buffer{new Book[BookShelf.size]}
{
    std::copy(BookShelf.buffer, BookShelf.buffer + size, buffer);
    std::cout << "costruttore di copia invocato\n";  // TODO
}

/**
 * @brief Move constructor of Book Shelf:: Book Shelf object
 *
 * @param BookShelf bookshelf to move
 */
BookShelf::BookShelf(BookShelf&& BookShelf) : size{BookShelf.size}, capacity{BookShelf.capacity}, buffer{BookShelf.buffer}
{
    BookShelf.size = 0;
    BookShelf.capacity = INIT_CAPACITY;
    BookShelf.buffer = nullptr;
    std::cout << "costruttore di spostamento invocato\n";  // TODO
}

/**
 * @brief operator[] overload with copy
 *
 * @param i index to get
 * @return Book
 */
Book BookShelf::operator[](int i) const
{
    return buffer[i];
}

/**
 * @brief operator[] overload with address
 *
 * @param i index to get
 * @return Book&
 */
Book& BookShelf::operator[](int i)
{
    return buffer[i];
}

/**
 * @brief Returns reference to object in index i
 *
 * @param i index to get
 * @return const Book&
 */
const Book& BookShelf::at(int i) const
{
    if (i >= 0 && i < size) {
        return buffer[i];
    }
    throw out_of_range();
}

/**
 * @brief Returns reference to object in index i
 *
 * @param i index to get
 * @return Book&
 */
Book& BookShelf::at(int i)
{
    if (i >= 0 && i < size) {
        return buffer[i];
    }
    throw out_of_range();
}

/**
 * @brief Adds element to the end of the bookshelf
 *
 * @param elem book to add
 */
void BookShelf::push_back(Book elem)
{
    if (size == capacity) {
        reserve(2 * capacity);
    }
    buffer[size] = elem;
    size++;
}

/**
 * @brief Removes element from the end and returs it
 *
 * @return book to return
 */
Book BookShelf::pop_back()
{
    if (size > 0) {
        size--;
        return buffer[size];
    }
    throw empty_vector();
}

/**
 * @brief Assign operator for reference
 *
 * @param BookShelf bookshelf to assign
 * @return BookShelf&
 */
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

/**
 * @brief Assign operator for rvalue reference
 *
 * @param BookShelf bookshelf to move
 * @return BookShelf&
 */
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

/**
 * @brief Returns bookshelf size
 *
 * @return int size
 */
int BookShelf::get_size() const
{
    return size;
}

/**
 * @brief Reserves menmory for the buffer
 *
 * @param n capacity of buffer
 */
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
