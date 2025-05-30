#include <iostream>
#include <string>
#include <stdexcept>


using namespace std;

class Employee {
private:
    string name;
    string employeeID;
    double baseSalary;
    double currentSalary;
    int performanceRating; 
  
    bool isValidPerformance(int rating) const {
        return (rating >= 1 && rating <= 5);
    }

    // Calculate salary based on performance
    void calculateSalary() {
        switch(performanceRating) {
            case 1: 
                currentSalary = baseSalary * 0.9; 
                break;
            case 2: 
                currentSalary = baseSalary * 0.95;
                break;
            case 3: 
                currentSalary = baseSalary;
                break;
            case 4: 
                currentSalary = baseSalary * 1.1; 
                break;
            case 5: 
                currentSalary = baseSalary * 1.2; 
                break;
        }
    }

public:
    // Constructor
    Employee(const string& empName, const string& id, double salary, int performance)
        : name(empName), employeeID(id), baseSalary(salary) {
        setPerformanceRating(performance);
    }

    // Set performance rating and recalculate salary
    void setPerformanceRating(int rating) {
        if (!isValidPerformance(rating)) {
            throw invalid_argument("Performance rating must be between 1-5");
        }
        performanceRating = rating;
        calculateSalary();
    }

    // Getter functions
    string getName() const { return name; }
    string getEmployeeID() const { return employeeID; }
    double getBaseSalary() const { return baseSalary; }
    double getCurrentSalary() const { return currentSalary; }
    int getPerformanceRating() const { return performanceRating; }

    // Display employee information
    void displayInfo() const {
        cout << "\nEmployee Information:\n";
        cout << "Name: " << name << endl;
        cout << "ID: " << employeeID << endl;
        cout << "Base Salary: $" << baseSalary << endl;
        cout << "Performance Rating: " << performanceRating << " (";
        switch(performanceRating) {
            case 1: cout << "Poor"; break;
            case 2: cout << "Below Average"; break;
            case 3: cout << "Average"; break;
            case 4: cout << "Above Average"; break;
            case 5: cout << "Excellent"; break;
        }
        cout << ")" << endl;
        cout << "Current Salary: $" << currentSalary << endl;
    }

    void setBaseSalary(double newSalary) {
        if (newSalary <= 0) {
            throw invalid_argument("Salary must be positive");
        }
        baseSalary = newSalary;
        calculateSalary(); // Recalculate based on new base salary
    }
};

int main() {
    try {
        Employee emp1("John Doe", "E1001", 50000.0, 3);
        Employee emp2("Jane Smith", "E1002", 60000.0, 5);
        Employee emp3("Bob Johnson", "E1003", 45000.0, 2);

        emp1.displayInfo();
        emp2.displayInfo();
        emp3.displayInfo();

        cout << "\nAfter performance updates:\n";
        emp1.setPerformanceRating(4); // Improved performance
        emp3.setPerformanceRating(1); // Performance declined
        emp1.displayInfo();
        emp3.displayInfo();

        try {
            emp2.setPerformanceRating(6); // Invalid rating
        } catch (const invalid_argument& e) {
            cout << "\nError: " << e.what() << endl;
        }


        emp2.setBaseSalary(65000.0);
        cout << "\nAfter salary adjustment:\n";
        emp2.displayInfo();

    } catch (const invalid_argument& e) 
    {
        cerr << "Error creating employee: " << e.what() << endl;
    }

    return 0;
}