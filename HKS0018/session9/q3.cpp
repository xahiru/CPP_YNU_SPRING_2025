#include <iostream>
#include <string>

using namespace std;

class Car {
    
private:
    string company;
    string model;
    int year;

public:
    void setCompany(const string& comp) {    
        company = comp;
    }

    void setModel(const string& mod) {
        model = mod;
    }

    void setYear(int yr) {
        year = yr;
    }
    string getCompany() const {
        return company;
    }

    string getModel() const {
        return model;
    }

    int getYear() const {
        return year;
    }
    void displayInfo() const {
        cout << "Company: " << company << endl;
        cout << "Model: " << model << endl;
        cout << "Year: " << year << endl;
    }
};

int main() {
    Car myCar;  // Create a Car object

    myCar.setCompany("Toyota");     // Set car properties using setter functions
    myCar.setModel("Camry");
    myCar.setYear(2022);

    cout << "Car Information:" << endl;
    myCar.displayInfo();

    cout << "\nAccessing individual properties:" << endl;
    cout << "Company: " << myCar.getCompany() << endl;
    cout << "Model: " << myCar.getModel() << endl;
    cout << "Year: " << myCar.getYear() << endl;

    myCar.setYear(2023);                                    // Update car properties
    cout << "\nUpdated Year: " << myCar.getYear() << endl;


    return 0;
    
}