# Define

Exception handling in C++ is a mechanism that allows you to handle runtime errors and exceptional situations gracefully.

# Try, Catch and Throw

**_Try block_**

The try block is used to enclose the code that might throw an exception.

**_Catch block_**

The catch block is used to catch and handle exceptions that are thrown within the corresponding try block.

###### Example

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

## Exception Classes

1. exception: The base class for all C++ standard library exceptions.
2. runtime_error: Represents errors that can be detected during runtime
3. logic_error
4. out_of_range
5. overflow_error
6. underflow_error
7. invalid_arguments
8. bad_alloc
9. length_error
10. domain_error

### Example

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
