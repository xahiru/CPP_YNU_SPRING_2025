#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
    string binary;
    int decimal = 0;

    // Take binary input from user
    cout << "Enter a binary number: ";
    cin >> binary;

    int length = binary.length();

    // Convert binary to decimal
    for (int i = 0; i < length; ++i) {
        if (binary[length - 1 - i] == '1') {
            decimal += pow(2, i);
        }
    }

    // Print the result
    cout << "Decimal equivalent: " << decimal << endl;

    return 0;
}
