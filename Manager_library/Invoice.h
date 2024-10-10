#ifndef INVOICE_H // Start of the include guard
#define INVOICE_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Invoice
{
    int id;
    string date;
    vector<pair<Book *, int>> items;
    double total;

public:
    // Invoice(int _id, string _date, vector<pair<Book *, int>> _items, double _total) : id(_id), date(_date), items(_items), total(_total) {}
    // void addItem(Book *book, int)
    // {
    //     book->items.push_back(pair<Book *, int>(book));
    // }
    // void display() const
    // {
    // }
};
#endif
