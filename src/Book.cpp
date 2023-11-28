#include "../include/Book.h"
#include "../include/Exception.h"

#include <iostream>

/**
 * @brief Construct a new Book:: Book object
 *
 */
Book::Book() {}

/**
 * @brief Construct a new Book:: Book object
 *
 * @param name author name
 * @param surname author surname
 * @param title book's title
 * @param isbn book's isbn
 */
Book::Book(std::string name, std::string surname, std::string title, std::string isbn) : _auth_name{name}, _auth_surname{surname}, _title{title}
{
    if (is_valid_isbn(isbn)) {
        _isbn = isbn;
    } else {
        throw Exception("Isbn is not valid");
    }
}

/**
 * @brief Construct a new Book:: Book object
 *
 * @param name author name
 * @param surname author surname
 * @param title book's title
 * @param isbn book's isbn
 * @param cp_date copyright date expire
 */
Book::Book(std::string name, std::string surname, std::string title, std::string isbn, Date cp_date) : _cp_date{cp_date}
{
    Book(name, surname, title, isbn);
}

/**
 * @brief Reserve book logic
 *
 */
void Book::reserve_book()
{
    if (_is_available) {
        _is_available = false;
    } else {
        throw Exception("Alredy reserved.");
    }
}

/**
 * @brief Return book logic
 *
 * @param date current date
 */
void Book::return_book()
{
    if (_is_available) {
        throw Exception("Not reserved.");
    } else {
        _is_available = true;
    }
}

/**
 * @brief Checks isbn validity
 *
 * @param isbn isbn to check
 * @return true
 * @return false
 */
bool Book::is_valid_isbn(std::string isbn) const
{
    return isbn.length() == 13;
    // return strip_isbn(isbn).length() == 10;
}

/**
 * @brief Equals operator overload
 *
 * @param a first book to compare
 * @param b second book to compare
 * @return true equals
 * @return false not equals
 */
bool operator==(const Book& a, const Book& b)
{
    return a.get_isbn() == b.get_isbn();
}

/**
 * @brief Not-equals operator overload
 *
 * @param a first book to compare
 * @param b second book to compare
 * @return true not equals
 * @return false equals
 */
bool operator!=(const Book& a, const Book& b)
{
    return a.get_isbn() != b.get_isbn();
}

/**
 * @brief Ostream operator overload
 *
 * @param os os stream
 * @param b book to send to the stream
 * @return std::ostream&
 */
std::ostream& operator<<(std::ostream& os, Book& b)
{
    return os << b.get_title() << '\n'
              << b.get_auth_name() << '\n'
              << b.get_auth_surname() << '\n'
              << b.get_isbn() << '\n';
}
