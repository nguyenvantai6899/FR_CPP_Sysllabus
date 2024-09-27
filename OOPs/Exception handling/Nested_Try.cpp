#include <iostream>
using namespace std;
class Student
{
    string name;
    double score;

public:
    Student(string _name, double _score) : name(_name), score(_score) {};
    string getName() const
    {
        return name;
    };
    int getScore() const
    {
        return score;
    };
};
int main()
{
    try
    {
        Student student("Alice", 111);
        try
        {
            if (student.getScore() < 0 || student.getScore() > 100)
            {
                throw invalid_argument("Score must be between 0 and 100");
            }
            cout << "Student Name: " << student.getName() << endl;
            cout << "Score: " << student.getScore() << endl;
        }
        catch (const invalid_argument &e)
        {
            cerr << e.what() << '\n';
        }
    }
    catch (const exception &e)
    {
        cerr << e.what() << '\n';
    }
}