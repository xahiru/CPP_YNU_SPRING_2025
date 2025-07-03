#include <iostream>
#include <stdexcept>

using namespace std;

class Date {
private:
    int day;
    int month;
    int year;

    bool isLeapYear(int y) const {
        return (y % 400 == 0) || (y % 100 != 0 && y % 4 == 0);
    }
    int daysInMonth(int m, int y) const {
        if (m == 2) {
            return isLeapYear(y) ? 29 : 28;
        }
        if (m == 4 || m == 6 || m == 9 || m == 11) {
            return 30;
        }
        return 31;
    }


    bool isValidDate(int d, int m, int y) const {
        if (y < 1) return false;
        if (m < 1 || m > 12) return false;
        if (d < 1 || d > daysInMonth(m, y)) return false;
        return true;
    }

public:
    Date(int d, int m, int y) {
        setDate(d, m, y);
    }
    Date() : day(1), month(1), year(2000) {}

    void setDay(int d) {
        if (!isValidDate(d, month, year)) {
            throw invalid_argument("Invalid day for current month/year");
        }
        day = d;
    }

    void setMonth(int m) {
        if (m < 1 || m > 12) {
            throw invalid_argument("Month must be between 1 and 12");
        }
        if (!isValidDate(day, m, year)) {
            throw invalid_argument("Invalid day for the new month");
        }
        month = m;
    }

    void setYear(int y) {
        if (y < 1) {
            throw invalid_argument("Year must be positive");
        }
        if (!isValidDate(day, month, y)) {
            throw invalid_argument("Invalid date for the new year");
        }
        year = y;
    }
    void setDate(int d, int m, int y) {
        if (!isValidDate(d, m, y)) {
            throw invalid_argument("Invalid date");
        }
        day = d;
        month = m;
        year = y;
    }
    int getDay() const { return day; }
    int getMonth() const { return month; }
    int getYear() const { return year; }

    void display() const {
        cout << day << "/" << month << "/" << year;
    }

    void nextDay() {
        day++;
        if (day > daysInMonth(month, year)) {
            day = 1;
            month++;                          // Function to increment date by one day
            if (month > 12) {
                month = 1;
                year++;
            }
        }
    }
};

int main() {
    try {
        Date today(15, 6, 2023);
        cout << "Today: ";
        today.display();
        cout << endl;

        today.nextDay();
        cout << "Tomorrow: ";
        today.display();
        cout << endl;

        Date leapDay(28, 2, 2020);
        leapDay.nextDay();                //Test leap year
        cout << "Next day after Feb 28, 2020: ";
        leapDay.display();
        cout << endl;

        try {                                 // Test invalid dates
            Date invalid(31, 4, 2023); // April doesn't have 31 days
        } catch (const invalid_argument& e) {
            cout << "Error: " << e.what() << endl;
        }
        Date testDate(1, 1, 2000);
        testDate.setMonth(2);
        testDate.setDay(29); // Should work for 2000 (leap year)
        cout << "Leap day: ";
        testDate.display();
        cout << endl;

        testDate.setYear(2023); // 2023 is not a leap year
        testDate.setDay(29);   
    } catch (const invalid_argument& e) {

        cout << "Error: " << e.what() << endl;
    }
    

    return 0;
}