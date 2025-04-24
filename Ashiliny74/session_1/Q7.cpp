#include <iostream>

using namespace std;

int main() {
    int number;

    // Input value
    cout << "Enter an integer: ";
    cin >> number;

    // Check if the number is even or odd
    if (number % 2 == 0) {
        cout << number << " is an Even Number." << endl;
    } else {
        cout << number << " is an Odd Number." << endl;
    }

    return 0;
}