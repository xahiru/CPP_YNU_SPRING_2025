#include <iostream>

using namespace std;

int main() {
    int a, b, c;

    // Input values
    cout << "Enter three numbers: ";
    cin >> a >> b >> c;

    // Determine the largest number
    if (a >= b && a >= c) {
        cout << a << " is the largest." << endl;
    } else if (b >= a && b >= c) {
        cout << b << " is the largest." << endl;
    } else {
        cout << c << " is the largest." << endl;
    }

    return 0;
    