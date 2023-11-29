#ifndef BOOK_H
#define BOOK_H

#include "Date.h"

#include <string>

class Book
{
private:
    std::string _isbn{"000-000-000-0"};
    std::string _title{"[no title]"};
    std::string _auth_name{"Jhon"};
    std::string _auth_surname{"Doe"};
    Date _cp_date;
    Date _return_date;  // stores the expected return date for the return of this book (we chose to give the costumer
                        // a month of time by default to return the book)
    bool _is_available{true};

    bool is_valid_isbn(const std::string& isbn) const;   // checks the validity of the ISBN
    bool is_return_in_time(const Date& date) const;     // checks if the return date is exceded

public:
    Book();
    Book(std::string name, std::string surname, std::string title, std::string isbn);
    Book(std::string name, std::string surname, std::string title, std::string isbn, Date cp_date);

    // get functions
    std::string get_isbn() const { return _isbn; }
    std::string get_title() const { return _title; }
    std::string get_auth_name() const { return _auth_name; }
    std::string get_auth_surname() const { return _auth_surname; }
    std::string get_full_name() const { return _auth_name + " " + _auth_surname; }
    const Date& get_cp_date() const { return _cp_date; }
    bool is_available() const { return _is_available; }

    // set function
    void set_cp_date(const Date& cp_date) { _cp_date = cp_date; }

    // utilities functions to manage reservation and return of the book
    void reserve_book(const Date& date);
    void return_book(const Date& date);
};

std::ostream& operator<<(std::ostream& os, const Book& b);
bool operator==(const Book& a, const Book& b);
bool operator!=(const Book& a, const Book& b);

#endif
