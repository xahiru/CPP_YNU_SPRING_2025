#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
    string binary;
    int decimal = 0;

    cout << "Enter a binary number: ";
    cin >> binary;

    int length = binary.length();

    for (int i = 0; i < length; ++i) {
        if (binary[length - 1 - i] == '1') {
            decimal += pow(2, i);
        }
    }

 
    cout << "Decimal equivalent: " << decimal << endl;

    return 0;
}
