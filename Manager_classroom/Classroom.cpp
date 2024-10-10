#include "Classroom.h"
#include <algorithm>

void Classroom::addStudent(shared_ptr<Student> std)
{
    Classroom::students.push_back(std);
}

void Classroom::removeStudent(shared_ptr<Student> std)
{
    auto it = find(Classroom::students.begin(), Classroom::students.end(), std);
    if (it != Classroom::students.end())
    {
        Classroom::students.erase(it);
        cout << "Student " << std->getName() << " has been removed" << endl;
    }
    else
    {
        cout << "Student " << std->getName() << " not exists" << endl;
    }
}
void Classroom::addLeader(shared_ptr<Student> std)
{
    leader = std;
    if (auto ld = leader.lock())
    {
        cout << "Leader is " << ld->getName() << endl;
    }
}
void Classroom::displayStudent()
{
    for (auto &s : Classroom::students)
    {
        s->Display();
    }
}