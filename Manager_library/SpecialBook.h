#ifndef SPECIALBOOK_H // Start of the include guard
#define SPECIALBOOK_H
#include <string>
#include <iostream>
#include "Book.h"

using namespace std;

class SpecialBook : public Book
{
public:
    SpecialBook(int _id, string _title, string _author, double _price, int _stock)
        : Book(_id, _title, _author, _price, _stock) {}
    double getPrice() const override
    {
        return Book::getPrice() * 1.2;
    }
    void Display() const override
    {
        cout << "Special Book - ";
        Book::Display(); // Gọi phương thức Display() của lớp cha
    }
};
#endif // End of the include guard