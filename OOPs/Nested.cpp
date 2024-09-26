#include <iostream>
using namespace std;

class Person
{
    class Address
    {
    private:
        string city;
        string street;

    public:
        Address(string _city, string _street) : city(_city), street(_street) {};
        void Display()
        {
            cout << city << endl;
            cout << street << endl;
        }
    };
    string name;
    int age;
    Address address;

public:
    Person(string _name, int _age, string _city, string _street) : name(_name), age(_age), address(_city, _street) {};

    void Display()
    {
        cout << name << endl;
        cout << age << endl;
        address.Display();
    }
};
int main()
{
    Person person("John", 20, "LA", "123 abc street");
    person.Display();
    return 0;
}