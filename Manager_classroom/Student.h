#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>

using namespace std;
class Student
{
private:
    string name;
    int age;
    double gpa;

public:
    Student(const string &_name, int _age, double _gpa);
    ~Student();

    string getName();
    void setName(const string &_name);

    int getAge();
    void setAge(int _age);

    double getGpa();
    void setGpa(double _gpa);

    void Display();
};

#endif
