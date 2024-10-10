#ifndef BOOK_H // Start of the include guard
#define BOOK_H
#include <string>
#include <iostream>

using namespace std;

class Book
{
private:
    int id;
    string title;
    string author;
    double price;
    int stock;

public:
    // Constructor
    Book(int _id, string _title, string _author, double _price, int _stock)
        : id(_id), title(_title), author(_author), price(_price), stock(_stock) {}

    // Get price
    virtual double getPrice() const { return price; }

    // Get ID
    int getID() const { return id; }

    // Get author
    string getAuthor() const { return author; }

    // Sell method
    void sell(int quantity)
    {
        if (quantity > stock)
        {
            cout << "Not enough stock to sell." << endl;
        }
        else
        {
            stock -= quantity;
        }
    }

    // Display method
    virtual void Display() const
    {
        cout << "Title: " << title << ", Author: " << author << ", Price: " << price << ", Stock: " << stock << endl;
    }
};
#endif