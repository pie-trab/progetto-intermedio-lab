#include "../include/BookShelf.h"
#include "../include/Book.h"
#include "../include/Exception.h"

void default_constructor();
void no_date_constructor();
void date_constructor();
void exception_handling();
void get_test();
void set_date();
void test_operator();
void test_reserve_return();

void default_constructor_test();
void int_constructor_test();
void destructor_test();
void copy_constructor_test();
void move_constructor_test();
void initializer_list_constructor_test();
void array_element_operator_test();
void at_test();
void push_back_test();
void pop_back_test();
void copy_operator_test();
void move_operator_test();
BookShelf move_test();

int main(int argc, char const* argv[])
{
    default_constructor();
    std::cout << "------------------" << '\n';
    no_date_constructor();
    std::cout << "------------------" << '\n';
    date_constructor();
    std::cout << "------------------" << '\n';
    exception_handling();
    std::cout << "------------------" << '\n';
    get_test();
    std::cout << "------------------" << '\n';
    set_date();
    std::cout << "------------------" << '\n';
    test_operator();
    std::cout << "------------------" << '\n';
    test_reserve_return();

    std::cout << "------------------" << '\n';
    default_constructor_test();
    std::cout << "------------------" << '\n';
    int_constructor_test();
    std::cout << "------------------" << '\n';
    destructor_test();
    std::cout << "------------------" << '\n';
    copy_constructor_test();
    std::cout << "------------------" << '\n';
    move_constructor_test();
    std::cout << "------------------" << '\n';
    initializer_list_constructor_test();
    std::cout << "------------------" << '\n';
    array_element_operator_test();
    std::cout << "------------------" << '\n';
    at_test();
    std::cout << "------------------" << '\n';
    push_back_test();
    std::cout << "------------------" << '\n';
    pop_back_test();
    std::cout << "------------------" << '\n';
    copy_operator_test();
    std::cout << "------------------" << '\n';
    move_operator_test();
    std::cout << "------------------" << '\n';
    move_test();

    return 0;
}

// test Book
void default_constructor()
{
    Book defBook;

    std::cout << "Default constructor: " << '\n';
    std::cout << defBook << '\n';
}

void no_date_constructor()
{
    Book myBook("David", "Foster Wallace", "Una cosa divertente che non farò mai più", "887-521-837-4");

    std::cout << "Constructor without date: " << '\n';
    std::cout << myBook << '\n';
}

void date_constructor()
{
    Date d(1997, Month::feb, 1);
    Book myBook("David", "Foster Wallace", "Una cosa divertente che non farò mai più", "887-521-837-4", d);

    std::cout << "Constructor with date: " << '\n';
    std::cout << myBook << '\n';
}

void exception_handling()
{
    Date d(1900, Month::aug, 23);

    std::cout << "Exception handling: " << '\n';
    try {
        Book invalidBook("David", "Foster Wallace", "Una cosa divertente che non farò mai più", "127347231974923174912374", d);
    } catch (Exception e) {
        std::cerr << e.get_message() << '\n';
    }
}

void get_test()
{
    Date d(1900, Month::aug, 23);

    Book myBook("David", "Foster Wallace", "Una cosa divertente che non farò mai più", "887-521-837-4", d);
    std::cout << "Get test: " << '\n';
    std::cout << myBook.get_isbn() << '\n';
    std::cout << myBook.get_title() << '\n';
    std::cout << myBook.get_auth_name() << '\n';
    std::cout << myBook.get_auth_surname() << '\n';
    std::cout << myBook.get_full_name() << '\n';
    std::cout << myBook.get_cp_date() << '\n';
    std::cout << myBook.is_available() << '\n';
}

void set_date()
{
    Date d(1900, Month::aug, 23);

    Book myBook("David", "Foster Wallace", "Una cosa divertente che non farò mai più", "887-521-837-4", d);
    std::cout << "set_cp_date: " << '\n';

    myBook.set_cp_date(d);
    std::cout << myBook.get_cp_date() << '\n';
}

void test_operator()
{
    Date d(1900, Month::aug, 23);

    std::cout << "operator== and operator!=: " << '\n';
    Book testBook1("David", "Foster Wallace", "Una cosa divertente che non farò mai più", "900-521-837-4", d);
    Book testBook2("David", "Foster Wallace", "Una cosa divertente che non farò mai più", "800-521-837-4", d);

    std::cout << (testBook1 == testBook2) << '\n';
    std::cout << (testBook1 != testBook2) << '\n';
}

void test_reserve_return()
{
    Date d(1900, Month::aug, 23);

    std::cout << "reserve and return " << '\n';
    Book testBook3("Herman", "Melville", "Moby Dick", "800-700-600-1", d);
    Book testBook4("Robert", "Louis Stevenson", "L'isola del tesoro", "300-200-100-2", d);

    testBook3.return_book(Date{2023, Month::nov, 29});

    testBook3.reserve_book(Date{2023, Month::nov, 29});
    testBook3.return_book(Date{2023, Month::nov, 30});

    testBook3.reserve_book(Date{2023, Month::nov, 29});
    testBook3.reserve_book(Date{2023, Month::dec, 10});
    testBook3.reserve_book(Date{2024, Month::jan, 10});
    testBook3.return_book(Date{2024, Month::nov, 30});
}

// test BookShelf
void default_constructor_test()
{
    std::cout << "Default constructor" << '\n';
    BookShelf myVector;
}

void int_constructor_test()
{
    std::cout << "Constructor with int length" << '\n';
    BookShelf myVector = BookShelf(4);
}

void destructor_test()
{
    std::cout << "Destroier test" << '\n';
    BookShelf v1 = BookShelf(3);
    BookShelf v2;
    v1 = v1;
}

void copy_constructor_test()
{
    Date d(1900, Month::aug, 23);

    Book testBook1("David", "Foster Wallace", "Una cosa divertente che non farò mai più", "887-521-837-4", d);
    Book testBook2("Herman", "Melville", "Moby Dick", "800-700-600-1", d);
    Book testBook3("Robert", "Louis Stevenson", "L'isola del tesoro", "300-200-100-2", d);

    std::cout << "Copy construtor" << '\n';
    BookShelf v1 = {testBook1, testBook2, testBook3};
    BookShelf v2 = v1;
    for (int i = 0; i < 3; i++) {
        std::cout << v2.at(i) << " ";
    }
    std::cout << '\n';
}

void move_constructor_test()
{
    std::cout << "Move constructor" << '\n';
    BookShelf v = move_test();
    for (int i = 0; i < 10; i++) {
        std::cout << v.at(i) << " ";
    }
    std::cout << '\n';
}

void initializer_list_constructor_test()
{
    Date d(1900, Month::aug, 23);

    std::cout << "Initializer list" << '\n';
    Book testBook1("David", "Foster Wallace", "Una cosa divertente che non farò mai più", "887-521-837-4", d);
    Book testBook2("Herman", "Melville", "Moby Dick", "800-700-600-1", d);
    Book testBook3("Robert", "Louis Stevenson", "L'isola del tesoro", "300-200-100-2", d);

    BookShelf v1 = {testBook1, testBook2, testBook3};
}

void array_element_operator_test()
{
    Date d(1900, Month::aug, 23);

    std::cout << "operator[] test" << '\n';
    Book testBook1("David", "Foster Wallace", "Una cosa divertente che non farò mai più", "887-521-837-4", d);
    Book testBook2("Herman", "Melville", "Moby Dick", "800-700-600-1", d);
    Book testBook3("Robert", "Louis Stevenson", "L'isola del tesoro", "300-200-100-2", d);

    BookShelf v = {testBook1, testBook2};
    std::cout << "secondo elemento: " << v[1] << std::endl;
    v[0] = testBook3;
    std::cout << "quarto elemento modificato: " << v[0] << std::endl;
}

void at_test()
{
    Date d(1900, Month::aug, 23);

    std::cout << std::endl
              << "at" << std::endl;
    Book testBook1("David", "Foster Wallace", "Una cosa divertente che non farò mai più", "887-521-837-4", d);
    Book testBook2("Herman", "Melville", "Moby Dick", "800-700-600-1", d);
    Book testBook3("Robert", "Louis Stevenson", "L'isola del tesoro", "300-200-100-2", d);

    BookShelf v = {testBook1, testBook2, testBook3};

    v.at(2) = testBook1;
    std::cout << "terzo elemento modificato: " << v.at(2) << std::endl;
    std::cout << "secondo elemento: " << v.at(1) << std::endl;
    try {
        v.at(-3);
    } catch (Exception e) {
        std::cout << e.get_message();
    }
    try {
        v.at(100);
    } catch (Exception e) {
        std::cout << e.get_message();
    }
}

void push_back_test()
{
    std::cout << "push_back() test" << std::endl;
    BookShelf v;
    for (int i = 0; i < 20; i++) {
        v.push_back(Book());
    }
    for (int i = 0; i < 20; i++) {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
}

void pop_back_test()
{
    Date d(1900, Month::aug, 23);

    std::cout << "pop_back() test" << std::endl;
    Book testBook1("David", "Foster Wallace", "Una cosa divertente che non farò mai più", "887-521-837-4", d);
    Book testBook2("Herman", "Melville", "Moby Dick", "800-700-600-1", d);
    Book testBook3("Robert", "Louis Stevenson", "L'isola del tesoro", "300-200-100-2", d);

    BookShelf v = {testBook1, testBook2, testBook3};

    for (int i = 0; i < 3; i++) {
        std::cout << v.pop_back() << " ";
    }
    std::cout << '\n';
}

void copy_operator_test()
{
    Date d(1900, Month::aug, 23);

    std::cout << "Copy operator test " << '\n';
    Book testBook1("David", "Foster Wallace", "Una cosa divertente che non farò mai più", "887-521-837-4", d);
    Book testBook2("Herman", "Melville", "Moby Dick", "800-700-600-1", d);
    Book testBook3("Robert", "Louis Stevenson", "L'isola del tesoro", "300-200-100-2", d);

    BookShelf v1 = {testBook1, testBook2};
    BookShelf v2 = {testBook3};
    v2 = v1;

    for (int i = 0; i < 2; i++) {
        std::cout << v2.at(i) << " ";
    }
    std::cout << '\n';
}

void move_operator_test()
{
    std::cout << "Move operator test" << std::endl;
    BookShelf v;
    v = move_test();
    for (int i = 0; i < 10; i++) {
        std::cout << v.at(i) << " ";
    }
    std::cout << std::endl;
}

BookShelf move_test()
{
    BookShelf test;
    for (int i = 0; i < 10; i++) {
        test.push_back(Book());
    }
    return test;
}