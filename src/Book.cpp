#include <ostream>
#include "../include/Book.h"

Book::Book(){
    // ???
} // TODO

Book::Book(std::string name, std::string surname, std::string title, std::string isbn):
    _auth_name{name},
    _auth_surname{surname},
    _title{title}
{
    if (is_valid_isbn(isbn)) {
        _isbn = isbn;
        } else {
            // TODO, maybe error?
        };
}

Book::Book(std::string name, std::string surname, std::string title, std::string isbn, Date cp_date){
    Book(name, surname, title, isbn);
    _cp_date = cp_date; // TODO check if is a valid date
}

// if there are more restrictions on isbns
bool Book::is_valid_isbn(std::string isbn){
    return isbn.length() == 16; // including dashes (-)
}

// TODO
void Book::reserve_book(Date reservation_date){
    if (_is_available){ _is_available = false;} // messaggio libro prenotato ??
    else{} // messaggio libro non prenotato ??
}
void Book::return_book(){
    if (!_is_available) {_is_available = true;} // messaggio libro restituito ??
    else {}// messaggio libro non restituito ??
}
// ETODO

bool operator==(const Book& a, const Book& b)
{
    return a.get_isbn() == b.get_isbn(); // verificare la logica
}

bool operator!=(const Date& a, const Date& b)
{
    return !(a==b);
}

std::ostream& operator<<(std::ostream& os, Book& b)
{
    return os << b.get_title() << '\n' 
            << b.get_auth_name() << '\n'
            << b.get_auth_surname() << '\n'
            << b.get_isbn() << '\n';
}
