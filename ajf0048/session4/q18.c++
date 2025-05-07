#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int binaryToDecimal(const string& binary) {
    int decimal = 0;
    int base = 1; // 2^0

    for (int i = binary.size() - 1; i >= 0; --i) {
        if (binary[i] == '1') {
            decimal += base;
        }
        base *= 2; // Increase base by power of 2
    }

    return decimal;
}

int main() {
    string binary = "101011";
    int decimal = binaryToDecimal(binary);

    cout << "Decimal Number = " << decimal << endl;

    return 0;
}