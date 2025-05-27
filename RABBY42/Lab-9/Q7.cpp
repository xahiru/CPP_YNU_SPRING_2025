#include <iostream>
using namespace std;

class Date {
private:
    int day, month, year;
    bool isLeapYear() {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }
public:
    void setDate(int d, int m, int y) {
        day = d;
        month = m;
        year = y;
    }
    bool validate() {
        if (month < 1 || month > 12) return false;
        int daysInMonth[] = {31,28 + isLeapYear(),31,30,31,30,31,31,30,31,30,31};
        return day >= 1 && day <= daysInMonth[month - 1];
    }
    void print() { cout << day << "/" << month << "/" << year << endl; }
};

int main() {
    Date d;
    d.setDate(29, 2, 2020);
    cout << (d.validate() ? "Valid" : "Invalid") << endl; // Valid
    return 0;
}