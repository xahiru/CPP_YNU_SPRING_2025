#include <iostream>
#include <string>
using namespace std;

class Car {
private:
    string company;
    string model;
    int year;
public:
    void setDetails(string c, string m, int y) {
        company = c;
        model = m;
        year = y;
    }
    string getCompany() { return company; }
    string getModel() { return model; }
    int getYear() { return year; }
};

int main() {
    Car myCar;
    myCar.setDetails("Toyota", "Corolla", 2020);
    cout << "Company: " << myCar.getCompany() << endl;
    cout << "Model: " << myCar.getModel() << endl;
    cout << "Year: " << myCar.getYear() << endl;
    return 0;
}