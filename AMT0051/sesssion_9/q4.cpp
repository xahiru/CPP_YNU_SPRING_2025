#include <iostream>
#include <string>

class Car {
private:
    std::string company_;
    std::string model_;
    int year_;

public:

    Car() : company_("Unknown"), model_("Unknown"), year_(0) {}

    Car(const std::string& company, const std::string& model, int year) {
        setCompany(company);
        setModel(model);
        setYear(year);
    }

    void setCompany(const std::string& company) {
        company_ = company;
    }

    void setModel(const std::string& model) {
        model_ = model;
    }

    void setYear(int year) {
        if (year >= 1886 && year <= 2100) {
            year_ = year;
        } else {
            std::cerr << "Warning: Invalid year. Setting to default year (2000)." << std::endl;
            year_ = 2000;
        }
    }

    std::string getCompany() const {
        return company_;
    }

    std::string getModel() const {
        return model_;
    }

    int getYear() const {
        return year_;
    }

    void display() const {
        std::cout << "\n========= Car Information =========" << std::endl;
        std::cout << "Company   : " << company_ << std::endl;
        std::cout << "Model     : " << model_ << std::endl;
        std::cout << "Year      : " << year_ << std::endl;
        std::cout << "===================================" << std::endl;
    }
};

int main() {
    std::string company, model;
    int year;

    std::cout << "Enter car company: ";
    std::getline(std::cin, company);

    std::cout << "Enter car model: ";
    std::getline(std::cin, model);

    std::cout << "Enter manufacturing year: ";
    std::cin >> year;

    Car myCar(company, model, year);
    myCar.display();

    return 0;
}
