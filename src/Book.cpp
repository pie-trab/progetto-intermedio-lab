#include "../include/Book.h"

#include <iostream>

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
        throw IllegalArgument();
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
 * @param date current date
 */
void Book::reserve_book(const Date& date)
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

/**
 * @brief Return book logic
 *
 * @param date current date
 */
void Book::return_book(const Date& date)
{
    if (_is_available) {
        std::cout << "Libro non prenotato." << '\n';
    } else {
        _is_available = true;
        if (date < _return_date) {
            std::cout << "Libro restituito in tempo." << '\n';
        } else {
            std::cout << "Libro restituito in ritardo." << '\n';
        }
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

/**
 * @brief Checks if the return date is exceded
 *
 * @param date current date
 * @return true return date exceded
 * @return false return date not exceded
 */
bool Book::is_return_in_time(const Date& date) const
{
    return _return_date > date;
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
