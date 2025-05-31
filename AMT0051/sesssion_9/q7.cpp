#include <iostream>

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
    Date() : day(1), month(1), year(2000) {}

    Date(int d, int m, int y) {
        setDate(d, m, y);
    }

    void setDate(int d, int m, int y) {
        if (isValidDate(d, m, y)) {
            day = d;
            month = m;
            year = y;
        } else {
            std::cerr << "Invalid date provided. Setting to default (01/01/2000)." << std::endl;
            day = 1;
            month = 1;
            year = 2000;
        }
    }

    bool isValidDate(int d, int m, int y) const {
        if (y < 1 || m < 1 || m > 12 || d < 1)
            return false;
        return d <= getDaysInMonth(m, y);
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

    void display() const {
        std::cout << "Date: ";
        if (day < 10) std::cout << "0";
        std::cout << day << "/";
        if (month < 10) std::cout << "0";
        std::cout << month << "/" << year << std::endl;
    }
};

int main() {
    int d, m, y;

    std::cout << "Enter day: ";
    std::cin >> d;

    std::cout << "Enter month: ";
    std::cin >> m;

    std::cout << "Enter year: ";
    std::cin >> y;

    Date myDate;
    myDate.setDate(d, m, y);
    myDate.display();

    return 0;
}
