#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
    string name;
    int employeeID;
    double salary;
public:
    void setDetails(string n, int id) {
        name = n;
        employeeID = id;
    }
    
    void calculateSalary(int performance) {
        salary = 30000 + (performance * 1000); 
    }
    
    void displayDetails() {
        cout << "Name: " << name << ", ID: " << employeeID << ", Salary: " << salary << endl;
    }
};

int main() {
    Employee emp;
    emp.setDetails("John Doe", 101);
    emp.calculateSalary(5);
    emp.displayDetails();
    return 0;
}
