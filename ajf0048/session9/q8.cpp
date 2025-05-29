#include <iostream>
using namespace std;

class Employee {
private:
    string name;
    int employeeID;
    double salary;

public:
    Employee(string n, int id, double s) : name(n), employeeID(id), salary(s) {}

    void setSalary(double s) { salary = s; }
    double getSalary() { return salary; }

    void calculateSalary(int performanceRating) {
        if (performanceRating >= 1 && performanceRating <= 3) {
            salary *= 1.1; // 10% increase
        } else if (performanceRating >= 4 && performanceRating <= 5) {
            salary *= 1.2; // 20% increase
        } else {
            cout << "Invalid performance rating" << endl;
        }
    }
};

int main() {
    Employee emp("John Doe", 12345, 50000.0);
    emp.calculateSalary(5);
    cout << "Updated Salary: " << emp.getSalary() << endl;
    return 0;
}