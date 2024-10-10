// #include <iostream>
// #include <vector>
// #include <memory>
// #include <algorithm>

// using namespace std;

// class Student
// {
// public:
//     Student(string _name) : name(_name) {}
//     string getName() const { return name; }

// private:
//     string name;
// };

// int main()
// {
//     vector<shared_ptr<Student>> students;

//     shared_ptr<Student> student1 = make_shared<Student>("John");
//     shared_ptr<Student> student2 = make_shared<Student>("Jane");

//     students.push_back(student1);
//     students.push_back(student2);

//     auto it = find(students.begin(), students.end(), student1);

//     if (it != students.end())
//     {
//         cout << "Found student: " << (*it)->getName() << endl; // In ra tên sinh viên
//     }
//     else
//     {
//         cout << "Student not found" << endl;
//     }

//     return 0;
// }
