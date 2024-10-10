#include "Student.h"
#include "Classroom.h"
#include <iostream>
#include <memory>
using namespace std;

int main()
{
    unique_ptr<Classroom> cr = make_unique<Classroom>();
    shared_ptr<Student> s1 = make_shared<Student>("Alice", 20, 8);
    shared_ptr<Student> s2 = make_shared<Student>("Bo", 20, 9);

    cr->addStudent(s1);
    cr->addStudent(s2);

    cr->addLeader(s1);
    cr->displayStudent();

    cr->removeStudent(s1);
    cr->displayStudent();
    return 0;
}
