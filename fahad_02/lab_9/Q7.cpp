#include <iostream>
using namespace std;

class Date {
private:
    int day, month, year;

    bool isValid() const {
        if (year < 1 || month < 1 || month > 12 || day < 1) return false;
        
        int maxDays;
        if (month == 2) {
            bool isLeap = (year % 400 == 0) || (year % 100 != 0 && year % 4 == 0);
            maxDays = isLeap ? 29 : 28;
        } else if (month == 4 || month == 6 || month == 9 || month == 11) {
            maxDays = 30;
        } else {
            maxDays = 31;
        }
        
        return day <= maxDays;
    }

public:
    Date(int d, int m, int y) : day(d), month(m), year(y) {
        if (!isValid()) {
            day = 1; month = 1; year = 2000;
            cout << "Invalid date! Set to default (01/01/2000).\n";
        }
    }

    void setDate(int d, int m, int y) {
        day = d; month = m; year = y;
        if (!isValid()) {
            day = 1; month = 1; year = 2000;
            cout << "Invalid date! Reset to default (01/01/2000).\n";
        }
    }

    void getDate(int &d, int &m, int &y) const { d = day; m = month; y = year; }

    void print() const {
        cout << day << "/" << month << "/" << year << "\n";
    }
};

int main() {
    Date d(31, 2, 2023); 
    d.print(); 

    d.setDate(29, 2, 2024); 
    d.print(); 

    return 0;
}