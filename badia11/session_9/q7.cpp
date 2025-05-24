#include <iostream>
using namespace std;

class Date {
private:
    int day, month, year;
    
    bool isLeapYear() {
        return (year % 400 == 0) || (year % 100 != 0 && year % 4 == 0);
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
    bool setDate(int d, int m, int y) {
        if (y < 1 || m < 1 || m > 12 || d < 1 || d > daysInMonth()) {
            return false;
        }
        day = d;
        month = m;
        year = y;
        return true;
    }
    
    int getDay() { return day; }
    int getMonth() { return month; }
    int getYear() { return year; }
    
    bool isValid() {
        return (year >= 1) && 
               (month >= 1 && month <= 12) && 
               (day >= 1 && day <= daysInMonth());
    }
};
