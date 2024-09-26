#include <iostream>
using namespace std;

class User
{
private:
    string name = "Alice";
    string password = "Wonderland";

public:
    void set(string name, string password)
    {
        /*pointer this. (User *this)*/
        this->name = name;
        this->password = password;
    }
    void get()
    {
        cout << name << " " << password << endl;
    }
};

int main()
{
    User obj;
    obj.get();
    obj.set("Tom", "Jerry");
    obj.get();
    return 0;
}
