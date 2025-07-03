#include <iostream>
#include <string>
using namespace std;

class Car {
private:
    string company;
    string model;
    int year;

public:
    Car(const string& comp, const string& mdl, int yr) 
        : company(comp), model(mdl), year(yr > 1885 ? yr : 1886) {
        if (yr <= 1885) cout << "Invalid year. Set to 1886." << endl;
    }

    void setCompany(const string& comp) { company = comp; }
    void setModel(const string& mdl) { model = mdl; }
    void setYear(int yr) { 
        if (yr > 1885) year = yr;
        else cout << "Invalid year!" << endl;
    }

    string getCompany() const { return company; }
    string getModel() const { return model; }
    int getYear() const { return year; }

    void display() const {
        cout << company << " " << model << " (" << year << ")" << endl;
    }
};

int main() {
    Car myCar("Toyota", "Corolla", 2020);
    myCar.display();
    return 0;
}