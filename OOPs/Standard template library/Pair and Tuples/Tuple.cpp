#include <iostream>
#include <tuple>

using namespace std;

int main()
{
    tuple<int, string, double> myData = make_tuple(1, "laptop", 1030.00);

    // in gia tri
    cout << "ID: " << get<0>(myData) << endl;
    cout << "Name: " << get<1>(myData) << endl;
    cout << "Price: " << get<2>(myData) << endl;

    // cap nhap gia tri

    get<1>(myData) = "laptop gaming";
    cout << "Name: " << get<1>(myData) << endl;

    // gan gi tri vao bien
    int id;
    string name;
    double price;
    tie(id, name, price) = myData;

    cout << "ID: " << id << "  Name: " << name << " Price: " << price << endl;
}