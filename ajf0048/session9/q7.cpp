#include <iostream>
using namespace std;

class Date {
private:
    int day;
    int month;
    int year;

    bool isValidDate(int d, int m, int y) {
        if (m < 1 || m > 12) return false;
        if (d < 1 || d > 31) return false;
        if ((m == 2 && d > 29) || ((m == 4 || m == 6 || m == 9 || m == 11) && d > 30)) return false;
        return true;
    }

public:
    Date(int d, int m, int y) {
        if (isValidDate(d, m, y)) {
            day = d;
            month = m;
            year = y;
        } else {
            cout << "Invalid date" << endl;
        }
    }

    void setDay(int d) { day = d; }
    void setMonth(int m) { month = m; }
    void setYear(int y) { year = y; }

    int getDay() { return day; }
    int getMonth() { return month; }
    int getYear() { return year; }
};

int main() {
    Date date(15, 5, 2023);
    cout << "Day: " << date.getDay() << endl;
    cout << "Month: " << date.getMonth() << endl;
    cout << "Year: " << date.getYear() << endl;
    return 0;
}