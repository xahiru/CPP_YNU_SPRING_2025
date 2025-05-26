#include <iostream>
#include <string>
using namespace std;

class Employee
{
private:
    string name;
    int employeeID;
    double salary;

public:
    Employee(string n, int id, double s) : name(n), employeeID(id), salary(s) {}

    void setPerformanceBonus(double performanceRating)
    {
        if (performanceRating >= 0.8)
            salary *= 1.10;
        else if (performanceRating >= 0.5)
            salary *= 1.05;
        else
            salary *= 0.95;
    }

    void displayInfo() const
    {
        cout << "Employee: " << name << endl;
        cout << "ID: " << employeeID << endl;
        cout << "Salary: $" << salary << endl;
    }
};

int main()
{
    Employee emp("John Doe", 1001, 50000.0);

    cout << "Initial Employee Details:" << endl;
    emp.displayInfo();

    emp.setPerformanceBonus(0.9);
    cout << "\nAfter Performance Review:" << endl;
    emp.displayInfo();

    return 0;
}