#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include <string>

using namespace std;

class Person
{
private:
    string name;
    int age;

public:
    Person(/* args */);
    ~Person();
    void showInfo();
};

#endif