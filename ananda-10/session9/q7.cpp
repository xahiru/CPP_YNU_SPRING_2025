#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
    string name;
    string employeeID;
    double salary;

public:
    
    Employee(string n, string id) {
        name = n;
        employeeID = id;
        salary = 0.0;
    }

    void setSalaryBasedOnPerformance(int performanceLevel) {
        switch (performanceLevel) {
            case 1:
                salary = 10000;
                break;
            case 2: 
                salary = 8000;
                break;
            case 3:
                salary = 6000;
                break;
            case 4: 
                salary = 4000;
                break;
            default:
                cout << "Invalid performance level. Salary not set." << endl;
                salary = 0.0;
        }
    }
    void displayInfo() const {
        cout << "\nEmployee Information:" << endl;
        cout << "Name: " << name << endl;
        cout << "Employee ID: " << employeeID << endl;
        cout << "Salary: $" << salary << endl;
    }
};

int main() {
    string name, id;
    int performance;

    cout << "Enter employee name: ";
    getline(cin, name);
    cout << "Enter employee ID: ";
    getline(cin, id);

    Employee emp(name, id);

    cout << "\nPerformance Levels:\n1. Excellent\n2. Good\n3. Average\n4. Poor" << endl;
    cout << "Enter performance level (1-4): ";
    cin >> performance;

    emp.setSalaryBasedOnPerformance(performance);
    emp.displayInfo();

    return 0;
}

