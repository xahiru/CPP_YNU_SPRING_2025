#include <iostream>
using namespace std;

class Date {
private:
    int day, month, year;

    bool isLeapYear() const {
        return (year % 400 == 0) || (year % 100 != 0 && year % 4 == 0);
    }

    int daysInMonth() const {
        if (month == 2) return isLeapYear() ? 29 : 28;
        if (month == 4 || month == 6 || month == 9 || month == 11) return 30;
        return 31;
    }

public:
    Date(int d, int m, int y) : day(d), month(m), year(y) {}

    bool isValid() const {
        if (year < 1) return false;
        if (month < 1 || month > 12) return false;
        if (day < 1 || day > daysInMonth()) return false;
        return true;
    }

    void display() const {
        cout << day << "/" << month << "/" << year 
             << " is " << (isValid() ? "valid" : "invalid") << endl;
    }
};

int main() {
    Date dates[] = {
        Date(29, 2, 2020),
        Date(31, 4, 2021),
        Date(15, 6, 1995)
    };

    for (const Date& date : dates) {
        date.display();
    }
    return 0;
}