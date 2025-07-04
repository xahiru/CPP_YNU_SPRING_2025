#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
    string name;
    int id;
    double salary;
public:
    Employee(string n, int i, double s) : name(n), id(i), salary(s) {}
    void setPerformanceBonus(double percentage) {
        salary *= (1 + percentage/100.0);
    }
    double getSalary() { return salary; }
};

int main() {
    Employee emp("John Doe", 1001, 50000.0);
    emp.setPerformanceBonus(10.0);
    cout << "New Salary: $" << emp.getSalary() << endl;
    return 0;
}