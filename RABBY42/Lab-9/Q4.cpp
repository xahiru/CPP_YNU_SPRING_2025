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
    Car car;
    car.setCompany("Toyota");
    car.setModel("Camry");
    car.setYear(2020);
    cout << car.getCompany() << " " << car.getModel() << " " << car.getYear() << endl;
    return 0;
}