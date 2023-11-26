#include "../include/BookShelf.h"
#include "../include/Book.h"

BookShelf::BookShelf()
{
    _shelf = MyVector();
}

BookShelf::BookShelf(int n)
{
    _shelf = MyVector(n);
}

void BookShelf::push_back(Book myBook)
{
    _shelf.push_back(myBook);
}

Book BookShelf::pop_back()
{
    return _shelf.pop_back();
}