#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
    string name;
    string employeeID;
    double salary;
public:
    Employee(string n, string id, double s) : name(n), employeeID(id), salary(s) {}
    void setPerformanceBonus(double percentage) {
        salary *= (1 + percentage/100);
    }
    void displayDetails() {
        cout << "Name: " << name << endl;
        cout << "ID: " << employeeID << endl;
        cout << "Salary: $" << salary << endl;
    }
};

int main() {
    Employee emp("John Doe", "E12345", 50000.0);
    emp.setPerformanceBonus(10.0); // 10% raise
    emp.displayDetails();
    return 0;
}