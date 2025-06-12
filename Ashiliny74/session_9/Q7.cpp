#include <iostream>
using namespace std;

class Date {
private:
    int day, month, year;
public:
    void setDate(int d, int m, int y) {
        day = d;
        month = m;
        year = y;
    }
    bool isValid() {
        if (year < 1 || month < 1 || month > 12 || day < 1) return false;
        int daysInMonth[] = {31, (year%4==0?29:28), 31,30,31,30,31,31,30,31,30,31};
        return day <= daysInMonth[month-1];
    }
    void printDate() {
        cout << day << "/" << month << "/" << year << endl;
    }
};

int main() {
    Date d;
    d.setDate(29, 2, 2024);
    cout << (d.isValid() ? "Valid" : "Invalid") << endl;
    return 0;
}