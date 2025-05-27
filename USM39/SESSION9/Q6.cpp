#include <iostream>
using namespace std;

class Date {
private:
    int day;
    int month;
    int year;

public:
    void setDate(int d, int m, int y) {
        if (isValid(d, m, y)) {
            day = d;
            month = m;
            year = y;
        } else {
            cout << "Invalid date" << endl;
        }
    }

    bool isValid(int d, int m, int y) {
        if (m < 1 || m > 12 || d < 1 || d > 31) return false;
        if (m == 2 && d > 29) return false;
        return true;
    }

    void getDate() {
        cout << day << "/" << month << "/" << year << endl;
    }
};

int main() {
    Date date;
    date.setDate(29, 2, 2020);
    date.getDate();
    return 0;
}
