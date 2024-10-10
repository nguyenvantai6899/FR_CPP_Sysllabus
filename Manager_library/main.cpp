#include <iostream>
#include "Book.h"
#include "SpecialBook.h"
#include "Invoice.h"

int main()
{
    Book book(1, "C++ Programming", "Teo", 100.00, 100);
    book.Display();

    SpecialBook spBook(2, "Advanced C++", "Teo", 150.00, 50);
    spBook.Display();

    cout << "Price of Special Book: " << spBook.getPrice() << endl;

    return 0;
}
