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