#include <iostream>
#include <string>

class Employee {
private:
    std::string name;
    std::string employeeID;
    double salary;

public:
    Employee() : name("Unknown"), employeeID("0000"), salary(0.0) {}

    Employee(const std::string& n, const std::string& id)
        : name(n), employeeID(id), salary(0.0) {}

    void setDetails(const std::string& n, const std::string& id) {
        name = n;
        employeeID = id;
    }

    void calculateSalary(double baseSalary, int performanceRating) {
        double bonusMultiplier = 0.0;

        switch (performanceRating) {
            case 5: bonusMultiplier = 0.30; break; // Excellent
            case 4: bonusMultiplier = 0.20; break; // Very Good
            case 3: bonusMultiplier = 0.10; break; // Good
            case 2: bonusMultiplier = 0.05; break; // Fair
            case 1: bonusMultiplier = 0.00; break; // Poor
            default:
                std::cerr << "Invalid performance rating. Salary not updated." << std::endl;
                return;
        }

        salary = baseSalary + (baseSalary * bonusMultiplier);
    }

    std::string getName() const {
        return name;
    }

    std::string getEmployeeID() const {
        return employeeID;
    }

    double getSalary() const {
        return salary;
    }

    void display() const {
        std::cout << "\n--- Employee Details ---" << std::endl;
        std::cout << "Name       : " << name << std::endl;
        std::cout << "Employee ID: " << employeeID << std::endl;
        std::cout << "Salary     : $" << salary << std::endl;
    }
};

int main() {
    std::string name, id;
    double baseSalary;
    int performanceRating;

    std::cout << "Enter employee name: ";
    std::getline(std::cin, name);

    std::cout << "Enter employee ID: ";
    std::getline(std::cin, id);

    std::cout << "Enter base salary: $";
    std::cin >> baseSalary;

    std::cout << "Enter performance rating (1 to 5): ";
    std::cin >> performanceRating;

    Employee emp(name, id);
    emp.calculateSalary(baseSalary, performanceRating);
    emp.display();

    return 0;
}
