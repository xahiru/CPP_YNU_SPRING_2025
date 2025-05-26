#include <iostream>
#include <string>
using namespace std;

class Car {
private:
    string company;
    string model;
    int year;

public:
    Car(string c, string m, int y) : company(c), model(m), year(y) {}

    void setCompany(string c) { company = c; }
    void setModel(string m) { model = m; }
    void setYear(int y) { year = y; }

    string getCompany() { return company; }
    string getModel() { return model; }
    int getYear() { return year; }
};

int main() {
    Car car("Toyota", "Corolla", 2022);
    cout << "Company: " << car.getCompany() << endl;
    cout << "Model: " << car.getModel() << endl;
    cout << "Year: " << car.getYear() << endl;
    return 0;
}