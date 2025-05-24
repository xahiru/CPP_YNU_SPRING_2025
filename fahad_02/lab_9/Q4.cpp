#include <iostream>
#include <string>

class Car {
private:
    std::string company;
    std::string model;
    int year;

public:
    Car(const std::string& comp, const std::string& mdl, int yr) 
        : company(comp), model(mdl), year(yr > 1885 ? yr : 1886) {
        if (yr <= 1885) {
            std::cout << "Invalid year. Setting to 1886 (first car year)." << std::endl;
        }
    }

    void setCompany(const std::string& comp) {
        company = comp;
    }

    void setModel(const std::string& mdl) {
        model = mdl;
    }

    void setYear(int yr) {
        if (yr > 1885) {
            year = yr;
        } else {
            std::cout << "Invalid year. Must be after 1885." << std::endl;
        }
    }

    std::string getCompany() const {
        return company;
    }

    std::string getModel() const {
        return model;
    }

    int getYear() const {
        return year;
    }

    void displayInfo() const {
        std::cout << "Company: " << company << std::endl;
        std::cout << "Model: " << model << std::endl;
        std::cout << "Year: " << year << std::endl;
    }
};

int main() {
    std::string comp, mdl;
    int yr;

    std::cout << "Enter car company: ";
    std::getline(std::cin, comp);

    std::cout << "Enter car model: ";
    std::getline(std::cin, mdl);

    std::cout << "Enter manufacturing year: ";
    std::cin >> yr;

    Car myCar(comp, mdl, yr);

    std::cout << "\nCar Information:" << std::endl;
    myCar.displayInfo();

    return 0;
}