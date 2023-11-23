#include <string>
#include "Date.h"

class Book{
    std::string _isbn;
    std::string _title;
    std::string _auth_name;
    std::string _auth_surname;
    Date _cp_date;
    
    // todo reservation handling
    Date _reservation_date;
    
    bool _is_available;
    
    
    bool is_valid_isbn(std::string isbn);
    
public:
    // constructors
    Book(); // todo
    Book(std::string name, std::string surname, std::string title, std::string isbn);
    Book(std::string name, std::string surname, std::string title, std::string isbn, Date cp_date);
    
    // get functions
    std::string get_isbn() const {return _isbn;};
    std::string get_title() const {return _title;};
    std::string get_auth_name() const {return _auth_name;};
    std::string get_auth_surname() const {return _auth_surname;};
    std::string get_full_name() const {return _auth_name + " " + _auth_surname;};
    Date get_cp_date() const {return _cp_date;};
    
    void set_date(Date cp_date);
    bool is_available() const {return _is_available;};
    
    
    // utilities functions 
    void reserve_book(Date reservation_date);
    void return_book();
    
    

    
};
    std::ostream& operator<<(std::ostream& os, Book& b);
    bool operator==(const Book& a, const Book& b);
    bool operator!=(const Book& a, const Book& b);