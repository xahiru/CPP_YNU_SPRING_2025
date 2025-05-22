#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
    string name;
    string employeeID;
    double salary;
public:
    void setDetails(string n, string id, double s) {
        name = n;
        employeeID = id;
        salary = s;
    }
    
    void adjustSalary(char performance) {
        switch(performance) {
            case 'A': salary *= 1.20; break; // 20% raise
            case 'B': salary *= 1.10; break; // 10% raise
            case 'C': salary *= 1.05; break; // 5% raise
            case 'D': break; // no change
            case 'F': salary *= 0.90; break; // 10% cut
        }
    }
    
    void display() {
        cout << "Name: " << name << endl;
        cout << "ID: " << employeeID << endl;
        cout << "Salary: " << salary << endl;
    }
};
