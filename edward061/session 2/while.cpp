#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Enter a non-negative integer: ";
    cin >> n;

    do {
        if (n < 0) {
            cout << "The integer you entered is negative." << endl;
            cout << "Enter a non-negative integer: ";
            cin >> n;
        }
    } while (n < 0);

    cout << "You entered a valid non-negative integer: " << n << endl;

    return 0;
}