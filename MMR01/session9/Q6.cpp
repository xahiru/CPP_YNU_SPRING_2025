#include <iostream>
#include <string>
#include <array>

using namespace std;

class Date {
private:
    int day;
    int month;
    int year;

    // Helper function to check if year is leap year
    bool isLeapYear(int y) const {
        return (y % 400 == 0) || (y % 100 != 0 && y % 4 == 0);
    }

    // Helper function to get days in month
    int daysInMonth(int m, int y) const {
        const array<int, 12> days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (m == 2 && isLeapYear(y)) {
            return 29;
        }
        return days[m - 1];
    }

public:
    // Constructor with validation
    Date(int d = 1, int m = 1, int y = 2000) {
        setDate(d, m, y);
    }

    // Set the complete date with validation
    bool setDate(int d, int m, int y) {
        if (isValidDate(d, m, y)) {
            day = d;
            month = m;
            year = y;
            return true;
        }
        // Set to default date if invalid
        day = 1;
        month = 1;
        year = 2000;
        return false;
    }

    // Validate date components
    bool isValidDate(int d, int m, int y) const {
        if (y < 1) return false; // No year 0 or negative
        if (m < 1 || m > 12) return false;
        if (d < 1 || d > daysInMonth(m, y)) return false;
        return true;
    }

    // Individual setters with validation
    bool setDay(int d) {
        if (isValidDate(d, month, year)) {
            day = d;
            return true;
        }
        return false;
    }

    bool setMonth(int m) {
        if (isValidDate(day, m, year)) {
            month = m;
            return true;
        }
        return false;
    }

    bool setYear(int y) {
        if (isValidDate(day, month, y)) {
            year = y;
            return true;
        }
        return false;
    }

    // Getters
    int getDay() const { return day; }
    int getMonth() const { return month; }
    int getYear() const { return year; }

    // Display date in DD/MM/YYYY format
    void display() const {
        cout << (day < 10 ? "0" : "") << day << "/" 
             << (month < 10 ? "0" : "") << month << "/" 
             << year;
    }

    // Display date in Month DD, YYYY format
    void displayLong() const {
        const array<string, 12> months = {
            "January", "February", "March", "April", "May", "June",
            "July", "August", "September", "October", "November", "December"
        };
        cout << months[month - 1] << " " << day << ", " << year;
    }
};

int main() {
    // Test valid date
    Date today(25, 12, 2023);
    cout << "Today is: ";
    today.display();
    cout << " (";
    today.displayLong();
    cout << ")\n";

    // Test invalid date
    Date invalid(31, 4, 2023);
    cout << "Invalid date adjusted to: ";
    invalid.display();
    cout << endl;

    // Test date modification
    Date testDate;
    if (testDate.setDate(29, 2, 2020)) {
        cout << "Valid leap year date: ";
        testDate.display();
    } else {
        cout << "Invalid date";
    }
    cout << endl;

    if (testDate.setDate(29, 2, 2021)) {
        cout << "Valid leap year date: ";
        testDate.display();
    } else {
        cout << "Invalid date (not a leap year) adjusted to: ";
        testDate.display();
    }
    cout << endl;

    return 0;
}