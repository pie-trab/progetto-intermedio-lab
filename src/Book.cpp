#include "../include/Book.h"

#include <iostream>

Book::Book()
{
}

Book::Book(std::string name, std::string surname, std::string title, std::string isbn) : _auth_name{name}, _auth_surname{surname}, _title{title}
{
    if (is_valid_isbn(isbn)) {
        _isbn = isbn;
    } else {
        // TODO, maybe error?
    };
}

Book::Book(std::string name, std::string surname, std::string title, std::string isbn, Date cp_date)
{
    Book(name, surname, title, isbn);
    _cp_date = cp_date;  // TODO check if is a valid date
}

bool Book::is_valid_isbn(std::string isbn) const
{
    if (isbn.length() == 13) {
    }

    return isbn.length() == 16;  // including dashes (-)
}

// formats isbn
std::string Book::strip_isbn(std::string isbn)
{
    std::string out;
    // checks for scpecial characters like '-'
    for (int i = 0; i < isbn.length(); i++) {
        if (isdigit(isbn[i])) {
            out += isbn[i];
        }
    }

    // returns if the stripped isbn is long 13 digits
    if (isbn.length() == 13) {
        return isbn;
    } else {
        throw Book::IllegalArgument();
    }
}

void Book::reserve_book(Date reservation_date)
{
    if (_is_available) {
        _is_available = false;
        _reservation_date = reservation_date;
        _reservation_date.add_month(1);  // add custom time
    } else {
        if (is_return_in_time(reservation_date)) {
            std::cout << "Libro occupato."
                      << "\n";
        } else {
            std::cout << "Libro occupato fuori dal periodo di prenotazione."
                      << "\n";
        }
    }
}

void Book::return_book()
{
    if (_is_available) {
        std::cout << "Libro non prenotato."
                  << "\n";
    } else {
        _is_available = true;
        std::cout << "Libro restituito."
                  << "\n";
    }
}

bool Book::is_return_in_time(const Date& date) const
{
    return date <= (_reservation_date + date);
}

bool operator==(const Book& a, const Book& b)
{
    return a.get_isbn() == b.get_isbn();  // verificare la logica
}

bool operator!=(const Book& a, const Book& b)
{
    return !(a == b);
}

std::ostream& operator<<(std::ostream& os, Book& b)
{
    return os << b.get_title() << '\n'
              << b.get_auth_name() << '\n'
              << b.get_auth_surname() << '\n'
              << b.get_isbn() << '\n';
}
