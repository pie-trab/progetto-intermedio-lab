#ifndef BOOK_H
#define BOOK_H

#include "Date.h"

#include <string>

class IllegalArgument
{
};

class Book
{
    std::string _isbn;
    std::string _title;
    std::string _auth_name;
    std::string _auth_surname;
    Date _cp_date;
    Date _return_date;
    bool _is_available;

    // std::string strip_isbn(std::string isbn) const;
    bool is_valid_isbn(const std::string isbn) const;
    bool is_return_in_time(const Date& date) const;

public:
    Book();
    Book(std::string name, std::string surname, std::string title, std::string isbn);
    Book(std::string name, std::string surname, std::string title, std::string isbn, Date cp_date);

    // get functions
    std::string get_isbn() const { return _isbn; };
    std::string get_title() const { return _title; };
    std::string get_auth_name() const { return _auth_name; };
    std::string get_auth_surname() const { return _auth_surname; };
    std::string get_full_name() const { return _auth_name + " " + _auth_surname; };
    Date get_cp_date() const { return _cp_date; };
    bool is_available() const { return _is_available; };

    void set_cp_date(const Date cp_date) { _cp_date = cp_date; }

    // utilities functions
    void reserve_book(const Date& date);
    void return_book(const Date& date);
};

std::ostream& operator<<(std::ostream& os, Book& b);
bool operator==(const Book& a, const Book& b);
bool operator!=(const Book& a, const Book& b);
#endif
