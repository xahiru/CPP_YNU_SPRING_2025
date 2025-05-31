#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
    string name;
    string id;
    double salary;

public:
    Employee(const string& n, const string& i, double s) 
        : name(n), id(i), salary(s) {}

    void adjustSalary(double performance) {
        if (performance >= 0.9) salary *= 1.15;
        else if (performance >= 0.7) salary *= 1.10;
        else if (performance >= 0.5) salary *= 1.05;
    }

    void display() const {
        cout << "Employee: " << name 
             << "\nID: " << id
             << "\nSalary: $" << salary << endl;
    }
};

int main() {
    Employee emp("John Doe", "E1001", 50000.0);
    emp.adjustSalary(0.95);
    emp.display();
    return 0;
}