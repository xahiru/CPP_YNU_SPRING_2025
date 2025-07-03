#include <iostream>
#include <string>

class Car {
private:
    std::string company;
    std::string model;
    int year;

public:

    Car() {
        company = "";
        model = "";
        year = 0;
    }

    Car(std::string c, std::string m, int y) {
        company = c;
        model = m;
        year = y;
    }
    void setCompany(const std::string& c) {
        company = c;
    }

    void setModel(const std::string& m) {
        model = m;
    }

    void setYear(int y) {
        year = y;
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
    void displayCarInfo() const {
        std::cout << "Car Information:" << std::endl;
        std::cout << "Company: " << company << std::endl;
        std::cout << "Model: " << model << std::endl;
        std::cout << "Year: " << year << std::endl;
    }
};

int main() {
    std::string company, model;
    int year;

    std::cout << "Enter car company: ";
    std::getline(std::cin, company);
    std::cout << "Enter car model: ";
    std::getline(std::cin, model);
    std::cout << "Enter car year: ";
    std::cin >> year;

    Car car;
    car.setCompany(company);
    car.setModel(model);
    car.setYear(year);

    std::cout << std::endl;
    car.displayCarInfo();

    return 0;
}

