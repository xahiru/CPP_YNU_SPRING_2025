#include <iostream>
#include <string>
using namespace std;

class Car {
private:
    string company, model;
    int year;
public:
    void setCompany(string c) { company = c; }
    void setModel(string m) { model = m; }
    void setYear(int y) { year = y; }
    string getCompany() { return company; }
    string getModel() { return model; }
    int getYear() { return year; }
};

int main() {
    Car myCar;
    myCar.setCompany("Toyota");
    myCar.setModel("Camry");
    myCar.setYear(2023);
    cout << "Car: " << myCar.getCompany() << " " << myCar.getModel() << " " << myCar.getYear() << endl;
    return 0;
}