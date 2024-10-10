#ifndef Classroom_h
#define Classroom_h
#include "Student.h"
#include <iostream>
#include <vector>
#include <memory>
#include <string>
using namespace std;
class Classroom
{
private:
    string name;
    vector<shared_ptr<Student>> students;
    weak_ptr<Student> leader;

public:
    Classroom(/* args */) {}
    ~Classroom() {}
    void addStudent(shared_ptr<Student> std);
    void removeStudent(shared_ptr<Student> std);
    void addLeader(shared_ptr<Student> std);
    void displayStudent();
};
#endif