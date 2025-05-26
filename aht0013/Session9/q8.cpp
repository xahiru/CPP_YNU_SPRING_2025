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
    
    void setPerformance(double rating) {
        if (rating >= 0.8 && rating <= 1.2) {
            salary *= rating;
        }
    }
    
    string getName() { return name; }
    string getID() { return employeeID; }
    double getSalary() { return salary; }
};

int main() {
    Employee emp("John Doe", "E12345", 50000.0);
    cout << "Initial salary: " << emp.getSalary() << endl;
    
    emp.setPerformance(1.1);      // 10% raise
    cout << "New salary: " << emp.getSalary() << endl;
    
    return 0;
}