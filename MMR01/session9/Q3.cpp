#include <iostream>
#include <string>

class Car {
private:
    std::string company;
    std::string model;
    int year;

public:
    // Constructor to initialize car properties
    Car(const std::string& comp = "", const std::string& mdl = "", int yr = 0) {
        setCompany(comp);
        setModel(mdl);
        setYear(yr);
    }

    // Setter for company
    void setCompany(const std::string& comp) {
        company = comp;
    }

    // Setter for model
    void setModel(const std::string& mdl) {
        model = mdl;
    }

    // Setter for year with validation
    void setYear(int yr) {
        if (yr >= 1886 && yr <= 2024) { // First car was made in 1886
            year = yr;
        } else {
            std::cout << "Invalid year! Setting to 0." << std::endl;
            year = 0;
        }
    }

    // Getters
    std::string getCompany() const { return company; }
    std::string getModel() const { return model; }
    int getYear() const { return year; }

    // Display car information
    void displayInfo() const {
        std::cout << "\nCar Information:\n";
        std::cout << "Company: " << company << "\n";
        std::cout << "Model: " << model << "\n";
        std::cout << "Year: " << year << "\n";
    }
};

int main() {
    Car myCar; // Create a Car object

    // Get car details from user
    std::string comp, mdl;
    int yr;

    std::cout << "Enter car company: ";
    std::getline(std::cin, comp);

    std::cout << "Enter car model: ";
    std::getline(std::cin, mdl);

    std::cout << "Enter manufacturing year: ";
    std::cin >> yr;

    // Set car properties
    myCar.setCompany(comp);
    myCar.setModel(mdl);
    myCar.setYear(yr);

    // Display car information
    myCar.displayInfo();

    return 0;
}