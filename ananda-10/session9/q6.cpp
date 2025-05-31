#include <iostream>
using namespace std;

class Date {
private:
    int day;
    int month;
    int year;

    bool isLeapYear(int y) const {
        return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
    }

    int getDaysInMonth(int m, int y) const {
        switch (m) {
            case 2: return isLeapYear(y) ? 29 : 28;
            case 4: case 6: case 9: case 11: return 30;
            default: return 31;
        }
    }

public:
  
    Date(int d = 1, int m = 1, int y = 2000) : day(d), month(m), year(y) {}

    void setDay(int d) {
        day = d;
    }

    void setMonth(int m) {
        month = m;
    }

    void setYear(int y) {
        year = y;
    }

    int getDay() const {
        return day;
    }

    int getMonth() const {
        return month;
    }

    int getYear() const {
        return year;
    }

    bool isValidDate() const {
        if (year < 1 || month < 1 || month > 12 || day < 1)
            return false;

        int maxDay = getDaysInMonth(month, year);
        return day <= maxDay;
    }

    void displayDate() const {
        cout << (day < 10 ? "0" : "") << day << "/"
             << (month < 10 ? "0" : "") << month << "/"
             << year << endl;
    }
};

int main() {
    int d, m, y;

    cout << "Enter day: ";
    cin >> d;
    cout << "Enter month: ";
    cin >> m;
    cout << "Enter year: ";
    cin >> y;

    Date date(d, m, y);

    cout << "\nEntered Date: ";
    date.displayDate();

    if (date.isValidDate()) {
        cout << "The date is valid." << endl;
    } else {
        cout << "Invalid date!" << endl;
    }

    return 0;
}

