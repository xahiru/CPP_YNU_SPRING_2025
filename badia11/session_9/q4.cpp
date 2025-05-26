#include <iostream>
#include <string>
using namespace std;

class Car {
private:
    string company;
    string model;
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
    myCar.setModel("Corolla");
    myCar.setYear(2020);
    
    cout << "Company: " << myCar.getCompany() << endl;
    cout << "Model: " << myCar.getModel() << endl;
    cout << "Year: " << myCar.getYear() << endl;
    
    return 0;
}
