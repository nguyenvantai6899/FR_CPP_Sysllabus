#

- Default values for class is 1 byte
- int : 4 byte
- float : 4 byte
- string : 24 byte
- double : 8 byte

# Structure and Class

default value for constructor is undefined (structure and class)
example for structure:

```cpp
structure Employee {
int id;
int salary;
};

int main() {
Employee a;

    cout << "ID: " << a.id << endl; undefined
    cout << "Salary: " << a.salary << endl; undefined

    return 0;

}
```

# Constructor

- Constructors are automatically called when an object is created, while regular member functions must be called explicitly.

## Constructor copy

```cpp
class Car
{
public:
    string carName;

    // Parameterized constructor
    Car(string carName)
    {
        this->carName = carName;
    }

    // Copy Constructor
    Car(Car &c)
    {
        carName = c.carName;
    }
};
```

## Static

**_static data member_**

- Shared among all objects of the class.
- Only one copy for static variables.
  **_static data function_**
- Can be called without a specific object.
- Cannot access non-static member variables of the class.

```cpp
class MyClass
{
public:
    static int count;

    MyClass()
    {
        count++;
    }

    static void printCount()
    {
        cout << "Số lượng đối tượng: " << count << endl;
    }
};

int MyClass::count = 0;

int main()
{
    MyClass obj1;
    MyClass obj2;
    MyClass::printCount();
    return 0;
}
```

# Inheritance

## single inheritance

```cpp
#include <iostream>
using namespace std;

class Animals
{
public:
    string name;
    Animals(string name)
    {
        this->name = name;
    }
    virtual void Eat()
    {
        cout << name << "is eating" << endl;
    }
};
class Dog : public Animals
{
public:
    Dog(string name) : Animals(name) {}
    void Eat() override
    {
        cout << "Dog " << name << " is eating" << endl;
    }
    void Bark()
    {
        cout << name << "woof" << endl;
    }
};
int main()
{
    Dog dog("Bob");
    dog.Eat();
    dog.Bark();
}
```

# Object parameters

# Virtual Base class

- Virtual inheritance helps avoid multiple inheritance of the base class when there are multiple derived classes.
- It helps avoid ambiguity and minimizes the creation of unnecessary copies of the base class in the hierarchy.

```cpp

class Base {
public:
    Base() {
        cout << "Constructor of Base class called" << endl;
    }
    void show() {
        cout << "Base class show method" << endl;
    }
};

class Derived1 : virtual public Base {
public:
    Derived1() {
        cout << "Constructor of Derived1 class called" << endl;
    }
};

class Derived2 : virtual public Base {
public:
    Derived2() {
        cout << "Constructor of Derived2 class called" << endl;
    }
};

class FinalClass : public Derived1, public Derived2 {
public:
    FinalClass() {
        cout << "Constructor of FinalClass class called" << endl;
    }
};

int main() {
    FinalClass obj;
    obj.show();  // Gọi hàm show của Base
    return 0;
}

```

**_Result_**

```
Constructor of Base class called
Constructor of Derived1 class called
Constructor of Derived2 class called
Constructor of FinalClass class called
Base class show method

```

# Abstract Class

- Abstract class must contain at least one pure virtual function.
- Cannot create objects of an abstract class.
- Any class that inherits from an abstract class must provide implementations for all the pure virtual functions declared in the abstract class.

# Nested Class

# Upcasing

- Upcasting is an essential mechanism in polymorphism.
- It allows you to treat objects of derived classes as objects of their base class, enabling you to write code that operates on a base class pointer or reference and dynamically selects the appropriate derived class method to execute at runtime.

# Dynamic Methods

- Dynamic method dispatch allows you to call methods of different derived classes through a shared base class interface.
- It enables you to write code that can work with various derived class objects using a common interface, making your code more adaptable and extensible

```cpp
#include <iostream>

class Animal {
public:
    virtual void speak() {
        std::cout << "Animal speaks." << std::endl;
    }
};

class Dog : public Animal {
public:
    void speak() override {
        std::cout << "Dog barks." << std::endl;
    }
};

class Cat : public Animal {
public:
    void speak() override {
        std::cout << "Cat meows." << std::endl;
    }
};

int main() {
    Dog dog;
    Cat cat;

    Animal* animalPtr = &dog;  // Upcasting Dog to Animal
    animalPtr->speak();        // Dynamic dispatch: calls Dog's speak

    animalPtr = &cat;          // Upcasting Cat to Animal
    animalPtr->speak();        // Dynamic dispatch: calls Cat's speak

    return 0;
}

```

**_Results_**

```cpp
Dog barks.
Cat meows.
```
