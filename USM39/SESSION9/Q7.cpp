#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
    string name;
    int employeeID;
    double salary;

public:
    Employee(string n, int id) : name(n), employeeID(id), salary(0) {}

    void calculateSalary(int performance) {
        if (performance > 90) {
            salary = 100000;
        } else if (performance > 75) {
            salary = 75000;
        } else {
            salary = 50000;
        }
    }

    void display() {
        cout << "Name: " << name << ", ID: " << employeeID << ", Salary: " << salary << endl;
    }
};

int main() {
    Employee emp("John Doe", 12345);
    emp.calculateSalary(85);
    emp.display();
    return 0;
}
