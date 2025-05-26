#include <iostream>
using namespace std;

class Date {
private:
    int day;
    int month;
    int year;
public:
    void setDate(int d, int m, int y) {
        day = d;
        month = m;
        year = y;
    }
    bool isValid() {
        if (year < 1) return false;
        if (month < 1 || month > 12) return false;
        if (day < 1) return false;
        
        int maxDays;
        if (month == 2) {
            maxDays = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) ? 29 : 28;
        } else if (month == 4 || month == 6 || month == 9 || month == 11) {
            maxDays = 30;
        } else {
            maxDays = 31;
        }
        
        return day <= maxDays;
    }
    void printDate() {
        cout << day << "/" << month << "/" << year << endl;
    }
};

int main() {
    Date d;
    d.setDate(29, 2, 2020);
    cout << (d.isValid() ? "Valid" : "Invalid") << endl;
    d.printDate();
    return 0;
}