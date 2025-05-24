#include <iostream>
#include <string>
using namespace std;

int convertBinaryToDecimal(const string& binaryStr) {
    int decimalValue = 0;
    int base = 1;  

    for (int i = binaryStr.length() - 1; i >= 0; --i) {
        if (binaryStr[i] == '1') {
            decimalValue += base;
        }
        base *= 2;  
    }

    return decimalValue;
}

int main() {
    string binaryNumber = "101011";

    int decimal = convertBinaryToDecimal(binaryNumber);
    cout << "Decimal value of binary " << binaryNumber << " is: " << decimal << endl;

    return 0;
}
