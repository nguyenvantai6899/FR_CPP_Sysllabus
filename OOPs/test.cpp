#include <iostream>
using namespace std;

class Shape
{
    double area;

public:
    Shape() : area(0.0) {};
    virtual void printfArea()
    {
        cout << "Area: " << area << endl;
    }
};
class Rectangle : public Shape
{
    double width, height;

public:
    Rectangle(double _width, double _height) : width(_width), height(_height) {};
    void printfArea() override
    {
        cout << "Area of rectangle: " << width * height << endl;
    };
};
int main()
{
    Shape *s;
    Rectangle r(4, 6);

    s = &r;
    s->print Area();
}