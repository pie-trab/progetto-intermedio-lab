#include "../include/Book.h"

#include <iostream>

Book::Book()
{
}
/// Constructor
/// @param name
/// @param surname
/// @param title
/// @param isbn
Book::Book(std::string name, std::string surname, std::string title, std::string isbn) : _auth_name{name}, _auth_surname{surname}, _title{title}
{
    if (is_valid_isbn(isbn)) {
        _isbn = strip_isbn(isbn);
    } else {
        throw IllegalArgument();
    }
}

/// Construtor
/// @param name
/// @param surname
/// @param title
/// @param isbn
/// @param cp_date
Book::Book(std::string name, std::string surname, std::string title, std::string isbn, Date cp_date)
{
    Book(name, surname, title, isbn);
    _cp_date = cp_date;
}

/// Checks isbn validity
/// @param isbn
/// @return true: valid, false: invalid
bool Book::is_valid_isbn(std::string isbn) const
{
    return isbn.length() == 13;
    // return strip_isbn(isbn).length() == 10;
}

/**
/// Strips a string from special characters like '-' or spaces
/// @param str
/// @return stripped string
std::string Book::strip_isbn(std::string str) const
{
    std::string out;
    // checks for non-digit characters like '-'
    for (int i = 0; i < str.length(); i++) {
        if (isdigit(str[i])) {
            out += str[i];
        }
    }
    return out;
}
*/

/// Checks if the return date is exceded
/// @param date current date
/// @return true: return date exceded, false: return date not exceded
bool Book::is_return_in_time(const Date& date) const
{
    return _return_date > date;
}

/// Reserve book logic
/// @param date current date
void Book::reserve_book(Date date)
{
    if (_is_available) {
        _is_available = false;
        _return_date = date;
        _return_date.add_month(1);  // add custom time
    } else {
        if (is_return_in_time(date)) {
            std::cout << "Libro occupato." << '\n';
        } else {
            std::cout << "Libro occupato fuori dal periodo di prenotazione." << '\n';
        }
    }
}

void Book::return_book()
{
    if (_is_available) {
        std::cout << "Libro non prenotato." << '\n';
    } else {
        _is_available = true;
        std::cout << "Libro restituito." << '\n';
    }
}

/// Equals operator overload
/// @param a
/// @param b
/// @return true: equals, false: not equals
bool operator==(const Book& a, const Book& b)
{
    return a.get_isbn() == b.get_isbn();
}

/// Not equals operator overload
/// @param a
/// @param b
/// @return true: not equals, false: equals
bool operator!=(const Book& a, const Book& b)
{
    return a.get_isbn() != b.get_isbn();
}

/// Ostream operator overload
/// @param os
/// @param b
/// @return ostream operator
std::ostream& operator<<(std::ostream& os, Book& b)
{
    return os << b.get_title() << '\n'
              << b.get_auth_name() << '\n'
              << b.get_auth_surname() << '\n'
              << b.get_isbn() << '\n';
}
