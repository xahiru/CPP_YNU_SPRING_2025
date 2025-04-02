#include <iostream>
using namespace std;

bool isLeapYear(int year) {
    if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
        return true;
    else
        return false;
}

int main() {
    int year;
    cout << "Input: ";
    cin >> year;
    if (isLeapYear(year))
        cout << year << " is a Leap Year" << endl;
    else
        cout << year << " is not a Leap Year" << endl;
    return 0;
}