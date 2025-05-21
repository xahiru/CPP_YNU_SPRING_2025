#include <iostream>
#include <string>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    // English representations for numbers 1 to 9
    string numNames[] = {
        "zero", "one", "two", "three", "four", 
        "five", "six", "seven", "eight", "nine"
    };

    // Loop through the range from a to b
    for (int n = a; n <= b; ++n) {
        if (n >= 1 && n <= 9) {
            // Print the English representation for numbers 1 to 9
            cout << numNames[n] << endl;
        } else if (n > 9) {
            // Check if the number is even or odd
            if (n % 2 == 0) {
                cout << "even" << endl;
            } else {
                cout << "odd" << endl;
            }
        }
    }

    return 0;
}