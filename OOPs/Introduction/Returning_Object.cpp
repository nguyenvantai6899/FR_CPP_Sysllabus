#include <iostream>
#include <string>
using namespace std;

class Person
{
public:
    string name;

    Person(const string &_name) : name(_name) {}

    Person createPerson(const string newName) const
    {
        return Person(newName);
    }
};

int main()
{
    Person person("Alice");
    Person newPerson = person.createPerson("Bob");

    cout << "Original Person's Name: " << person.name << endl;
    cout << "New Person's Name: " << newPerson.name << endl;

    return 0;
}