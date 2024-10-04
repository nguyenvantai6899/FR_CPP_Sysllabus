#include <bits/stdc++.h>
using namespace std;

class Employee
{
private:
    int id;
    string name;

public:
    Employee() {};
    ~Employee()
    {
        cout << "Employee " << name << " destroyed" << endl;
    };
    void setName(const string _name) { this->name = _name; };
    string getName() const { return name; };
};

class Department
{
private:
    string name;
    vector<shared_ptr<Employee>> employees;
    weak_ptr<Employee> manager;

public:
    Department() {};
    ~Department()
    {
        cout << "Department is destroy" << endl;
    };
    string getName()
    {
        return name;
    }
    void setName(string _name)
    {
        this->name = _name;
    }
    void addEmployee(shared_ptr<Employee> employee)
    {
        employees.push_back(employee);
    }
    void addManager(shared_ptr<Employee> employee)
    {
        manager = employee;
    }
    void showEmployees()
    {
        cout << "Department " << name << " have " << employees.size() << " employ" << endl;
        for (auto &employee : employees)
        {
            cout << employee->getName() << endl;
        }
        if (auto mng = manager.lock())
        {
            cout << "Manager is " << mng->getName() << endl;
        }
    }
};
int main()
{
    unique_ptr<Employee> employee1 = make_unique<Employee>();
    employee1->setName("John");
    shared_ptr<Employee> employee2 = make_shared<Employee>();
    employee2->setName("Alice");
    shared_ptr<Employee> employee3 = make_shared<Employee>();
    employee3->setName("Tom");
    cout << employee2->getName() << " " << employee2.use_count() << endl;

    Department *department = new Department();
    // unique_ptr<Department> department = make_unique<Department>();
    department->setName("IT");
    // department->addEmployee(employee1);
    department->addEmployee(employee2);
    department->addEmployee(employee3);
    department->addManager(employee2);
    department->showEmployees();
    cout << employee2->getName() << " " << employee2.use_count() << endl;

    delete department;
    return 0;
}