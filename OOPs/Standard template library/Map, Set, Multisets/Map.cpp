#include <iostream>
#include <map>
using namespace std;

int main()
{
    map<string, int> myMap;
    myMap["John"] = 22;
    myMap.insert(make_pair("Tom", 24));
    myMap.insert(pair<string, int>("Thomas", 25));
    myMap["Alice"] = 21;
    cout << (myMap.rbegin())->first;
    for (auto &item : myMap)
    {
        cout << "Name: " << item.first << ", age: " << item.second << endl;
    }
}