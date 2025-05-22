#include <iostream>
using namespace std;

class Date {
private:
    int day;
    int month;
    int year;
    
    bool isLeapYear() {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }
    
    int daysInMonth() {
        if (month == 2) {
            return isLeapYear() ? 29 : 28;
        }
        if (month == 4 || month == 6 || month == 9 || month == 11) {
            return 30;
        }
        return 31;
    }
    
public:
    void setDate(int d, int m, int y) {
        if (y > 0 && m >= 1 && m <= 12 && d >= 1 && d <= daysInMonth()) {
            day = d;
            month = m;
            year = y;
        } else {
            day = 1;
            month = 1;
            year = 2000;
        }
    }
    
    int getDay() { return day; }
    int getMonth() { return month; }
    int getYear() { return year; }
    
    bool isValid() {
        return (year > 0 && month >= 1 && month <= 12 && day >= 1 && day <= daysInMonth());
    }
};

int main() {
    Date d;
    d.setDate(29, 2, 2020);
    cout << "Date: " << d.getDay() << "/" << d.getMonth() << "/" << d.getYear();
    cout << " is " << (d.isValid() ? "valid" : "invalid") << endl;
    return 0;
}