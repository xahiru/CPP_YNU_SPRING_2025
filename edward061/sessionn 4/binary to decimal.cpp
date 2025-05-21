#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int binaryToDecimal(string binary) {
    int decimal = 0;
    int length = binary.length();

    for (int i = 0; i < length; i++) {
    
        if (binary[i] == '1') {
            decimal += pow(2, length - i - 1); 
        }
    }
    
    return decimal;
}

int main() {
    string binary;

    cout << "Enter a binary number: ";
    cin >> binary;

    int decimal = binaryToDecimal(binary);

    cout << "Decimal equivalent: " << decimal << endl;

    return 0;
}