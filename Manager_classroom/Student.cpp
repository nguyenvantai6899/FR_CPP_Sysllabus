#include "Student.h"

Student::Student(const string &_name, int _age, double _gpa) : name(_name), age(_age), gpa(_gpa) {}
Student::~Student() {}

string Student::getName() { return name; }
void Student::setName(const string &_name) { name = _name; }

int Student::getAge() { return age; }
void Student::setAge(int _age) { age = _age; }

double Student::getGpa() { return gpa; }
void Student::setGpa(double _gpa) { gpa = _gpa; }

void Student::Display()
{
    cout << "Student name: " << name << ", Student age: " << age << ", Student gpa: " << gpa << endl;
}
