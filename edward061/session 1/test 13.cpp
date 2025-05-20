#include <iostream>
using namespace std;

int main() {
    int number;
    long long factorial = 1; 
    cout << "Enter a positive integer: ";
    cin >> number;

    if (number < 0) {
        cout << "Factorial of a negative number doesn't exist." << endl;
    } else {
        for (int i = 1; i <= number; ++i) {
            factorial *= i;
        }

        cout << "Factorial of " << number << " is " << factorial << endl;
    }

    return 0;
}