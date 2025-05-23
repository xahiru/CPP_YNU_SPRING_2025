#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Employee {
private:
    string name;
    string employeeID;
    double baseSalary;
    double currentSalary;
    int performanceRating; 

public:
    // Constructor
    Employee(const string& n = "", const string& id = "", double salary = 0.0, int rating = 3)
        : name(n), employeeID(id), baseSalary(salary), performanceRating(rating) {
        calculateSalary();
    }

    // Set performance rating (1-5) and recalculate salary
    bool setPerformanceRating(int rating) {
        if (rating >= 1 && rating <= 5) {
            performanceRating = rating;
            calculateSalary();
            return true;
        }
        return false;
    }

    // Calculate salary based on performance
    void calculateSalary() {
        switch (performanceRating) {
            case 1: currentSalary = baseSalary * 0.9; break;  
            case 2: currentSalary = baseSalary * 0.95; break; 
            case 3: currentSalary = baseSalary; break;        
            case 4: currentSalary = baseSalary * 1.1; break;  
            case 5: currentSalary = baseSalary * 1.2; break;  
            default: currentSalary = baseSalary;               
        }
    }

    // Setters with validation
    bool setBaseSalary(double salary) {
        if (salary >= 0) {
            baseSalary = salary;
            calculateSalary();
            return true;
        }
        return false;
    }

    void setName(const string& n) { name = n; }
    void setEmployeeID(const string& id) { employeeID = id; }

    // Getters
    string getName() const { return name; }
    string getEmployeeID() const { return employeeID; }
    double getBaseSalary() const { return baseSalary; }
    double getCurrentSalary() const { return currentSalary; }
    int getPerformanceRating() const { return performanceRating; }

    // Display employee information
    void display() const {
        cout << fixed << setprecision(2);
        cout << "\nEmployee Information:\n";
        cout << "Name: " << name << "\n";
        cout << "Employee ID: " << employeeID << "\n";
        cout << "Base Salary: $" << baseSalary << "\n";
        cout << "Performance Rating: " << performanceRating << "/5\n";
        cout << "Current Salary: $" << currentSalary << "\n";
        
        // Show performance impact
        double difference = currentSalary - baseSalary;
        if (difference > 0) {
            cout << "Performance Bonus: +$" << difference << "\n";
        } else if (difference < 0) {
            cout << "Performance Penalty: -$" << -difference << "\n";
        } else {
            cout << "No performance adjustment\n";
        }
    }
};

int main() {
    // Create employees
    Employee emp1("John Doe", "E1001", 50000.0, 4);
    Employee emp2("Jane Smith", "E1002", 60000.0, 2);

    // Display initial information
    cout << "Initial Employee Data:\n";
    emp1.display();
    emp2.display();

    // Update performance ratings
    emp1.setPerformanceRating(5); 
    emp2.setPerformanceRating(3); 

    // Display updated information
    cout << "\nAfter Performance Review:\n";
    emp1.display();
    emp2.display();

    // Test salary adjustment
    Employee emp3("Bob Johnson", "E1003", 45000.0);
    cout << "\nNew Employee Initial Data:\n";
    emp3.display();

    cout << "\nAfter Performance Rating Change (to 1):\n";
    emp3.setPerformanceRating(1);
    emp3.display();

    return 0;
}