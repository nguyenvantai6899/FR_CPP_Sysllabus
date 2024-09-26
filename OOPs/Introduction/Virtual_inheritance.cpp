#include <iostream>
using namespace std;

class Base
{
public:
    Base()
    {
        cout << "Constructor of Base class called" << endl;
    }
    void show()
    {
        cout << "Base class show method" << endl;
    }
};

class Derived1 : virtual public Base
{
public:
    Derived1()
    {
        cout << "Constructor of Derived1 class called" << endl;
    }
};

class Derived2 : virtual public Base
{
public:
    Derived2()
    {
        cout << "Constructor of Derived2 class called" << endl;
    }
};

class FinalClass : public Derived1, public Derived2
{
public:
    FinalClass()
    {
        cout << "Constructor of FinalClass class called" << endl;
    }
};

int main()
{
    FinalClass obj;
    obj.show(); // Gọi hàm show của Base
    return 0;
}
