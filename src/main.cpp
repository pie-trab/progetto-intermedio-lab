#include "../include/BookShelf.h"
#include "../include/Book.h"

int main(int argc, char const *argv[])
{
    Book mybook("David", "Foster Wallace", "Una cosa divertente che non farò mai più", "887-521-837-4");
    Book mybook1("David", "Foster Wallace", "Una cosa divertente che non farò mai più", "887-521-837-4");
    Book mybook2("David", "Foster Wallace", "Una cosa divertente che non farò mai più", "887-521-837-4");

    BookShelf shelf(10);

    shelf.push_back(mybook);
    shelf.push_back(mybook1);
    shelf.push_back(mybook2);

    Date d(2000, Month::aug, 10);
    Date d2(2000, Month::dec, 10);
    /*
        mybook.return_book(d);
        mybook.reserve_book(d);
        mybook.reserve_book(d);
        mybook.reserve_book(d2);
        mybook.return_book(d2);
        mybook.reserve_book(d2);
    */

    BookShelf book2 = {{"David", "Foster Wallace", "Una cosa divertente che non farò mai più", "887-521-837-4"},
                       {"David", "Foster Wallace", "Una cosa divertente che non farò mai più", "887-521-837-4"},
                       {"David", "Foster Wallace", "Una cosa divertente che non farò mai più", "887-521-837-4"}};

    book2[2].return_book(d);
    book2[2].reserve_book(d2);
    book2.at(2).return_book(d2);

    return 0;
}
