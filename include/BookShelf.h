#include "Book.h"
#include "MyVector.h"

class BookShelf
{
    MyVector _shelf;

public:
    BookShelf();
    BookShelf(int size);

    void push_back(Book myBook);
    Book pop_back();
};