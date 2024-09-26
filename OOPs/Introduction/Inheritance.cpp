#include <iostream>
using namespace std;

class Vehicle
{
protected:
    string brand;
    int year;

public:
    Vehicle(string _brand, int _year) : brand(_brand), year(_year) {}

    void Start()
    {
        cout << "Vehicle started" << endl;
    }

    virtual void Display()
    {
        cout << "Brand: " << brand << ", Year: " << year << endl;
    }
};

class Car : public Vehicle
{
private:
    int seatCount;

public:
    Car(string _brand, int _year, int _seatCount) : Vehicle(_brand, _year)
    {
        this->seatCount = _seatCount;
    }

    void Display() override
    {
        Vehicle::Display();
        cout << "Seats: " << seatCount << endl;
    }
};
class Bicycle : public Vehicle
{
private:
    bool hasBell;

public:
    Bicycle(string _brand, int _year, bool _hasBell) : Vehicle(_brand, _year), hasBell(_hasBell) {};
    void RingBell()
    {
        cout << "Bell ringing" << endl;
    }
    void Display() override
    {
        Vehicle::Display();
        cout << "Bell: " << hasBell << endl;
    }
};
class Motorbike : public Vehicle
{
private:
    string engineCapacity;

public:
    Motorbike(string _brand, int _year, string _engineCapacity) : Vehicle(_brand, _year), engineCapacity(_engineCapacity) {};

    void Display() override
    {
        Vehicle::Display();
        cout << "Capacity: " << engineCapacity << endl;
    };
};
int main()
{
    Car myCar("Toyota", 2021, 5);
    Bicycle myBicycle("Giant", 2019, true);
    Motorbike myMotorbike("Yamaha", 2021, "150cc");
    myCar.Display();
    myBicycle.Start();
    myBicycle.Display();
    myBicycle.RingBell();
    myMotorbike.Start();
    myMotorbike.Display();
    return 0;
}
