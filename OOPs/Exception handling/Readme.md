# Define

Exception handling in C++ is a mechanism that allows you to handle runtime errors and exceptional situations gracefully.

# Try, Catch and Throw

**_Try block_**

The try block is used to enclose the code that might throw an exception.

**_Catch block_**

The catch block is used to catch and handle exceptions that are thrown within the corresponding try block.

#### Example

```cpp
#include <iostream>
using namespace std;

int main() {
    try {
        // Code that might throw an exception
        int numerator = 10;
        int denominator = 0;

        if (denominator == 0) {
            throw "Division by zero is not allowed.";
        }

        int result = numerator / denominator;
        cout << "Result: " << result << endl;
    }
    catch (const char* error_message) {
        // Handle the exception
        cout << error_message << endl;
    }

    cout << "Program continues to execute after the exception." << endl;

    return 0;
}

```

# Exception Classes

1. exception: The base class for all C++ standard library exceptions.
2. runtime_error: Represents errors that can be detected during runtime

   > **ex**: div by zero, trying access to the file don't exists.

3. logic_error:Represents errors in the logic of a program, such as performing an invalid operation in a given context.
   > **ex**: Accessing an invalid array element.
4. out_of_range: Thrown when attempting to access an element beyond the valid range of a container.
   > **ex**: Accessing index 11 in an array of size 10.
5. overflow_error:Thrown when an arithmetic overflow occurs, where the value exceeds the limits of the data type
   > **ex**: Integer overflow, when a value surpasses the maximum limit of the int type.
6. underflow_error: Thrown when an arithmetic underflow occurs, where the value goes below the minimum limits of the data type.
   > **ex**: When a value is smaller than the minimum representable value of a data type.
7. invalid_arguments: Represents an error when an invalid argument is passed to a function.
   > **ex**: Passing a negative value to a square root function (sqrt(-1)).
8. bad_alloc: Thrown when dynamic memory allocation (using new) fails due to insufficient memory.
   > **ex**: When there's not enough memory to allocate a new object.
9. length_error: Represents an error when a container's size exceeds its maximum allowed length.
   > **ex**: Attempting to create a string or vector that exceeds the maximum allowed size.
10. domain_error: Thrown when a mathematical function is called with an argument outside its valid range.
    > **ex**: Passing a negative value to the sqrt() function.

#### Example

```cpp
#include <iostream>
using namespace std;

class InsufficientFundsException : public exception
{
    string msg;

public:
    InsufficientFundsException(string _msg) : msg(_msg) {};
    const char *what() const throw()
    {
        return msg.c_str();
    }
};

class BankAccount
{
private:
    int accountID;
    string customerName;
    double balance;

public:
    BankAccount(int _accountID, string _customerName, double _balance) : accountID(_accountID), customerName(_customerName), balance(_balance) {};
    BankAccount withDraw(const double &_amount)
    {
        if (_amount > this->balance)
        {
            throw InsufficientFundsException("Insufficient funds");
        }
        this->balance -= _amount;
        return BankAccount(accountID, customerName, balance);
    }
    void Display()
    {
        cout << "Account name: " << customerName << " balance: " << balance << endl;
    }
};

int main()
{
    try
    {
        BankAccount account1(1001, "Alice", 1000.0);
        account1.withDraw(2000.0);
        account1.Display();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}
```

> #### Note :

- The what() method in a user-defined exception class is used to provide an error message that describes the exception.
- The correct order for catch clauses in C++ is to catch more specific exceptions before catching more general exceptions. This is because C++ will execute the first catch clause that matches the exception type, and then it won't check the subsequent catch clauses. By catching more specific exceptions first, you ensure that you handle specialized cases before generic ones.
- If none of the catch clauses matches the type of the thrown exception, C++ does not execute any of them, and the program continues to run without handling the exception. This can lead to unexpected behavior or program termination if the exception is not ultimately caught.

# Nested Try Statements

Nested try statements in C++ refer to the use of one or more try-catch blocks within the body of another try-catch block

When an exception occurs within a nested try-catch structure, the first catch block associated with the innermost try block that can handle the exception is evaluated.

#### Example

```cpp
try {
    // Outer code
    try {
        // Inner code
    } catch (InnerExceptionType e) {
        // Handle InnerExceptionType here
    }
} catch (OuterExceptionType e) {
    // Handle OuterExceptionType here
}
```

```cpp
#include <iostream>
#include <stdexcept>
using namespace std;

int main()
{
    int num1, num2;
    cout << "Enter Number 1 & 2" << endl;
    cin >> num1 >> num2;
    try
    {
        try
        {
            if (cin.fail())
            {
                throw invalid_argument("Invalid number");
            }
            if (num2 == 0)
            {
                throw invalid_argument("Number 2 not 0");
            }
        }
        catch (const invalid_argument &e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    catch (...)
    {
        cout << "Invalid arguments";
    }
    return 0;
}
```
