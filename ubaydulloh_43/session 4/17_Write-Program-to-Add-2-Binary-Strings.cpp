#include <iostream>
#include <string>
using namespace std;

int main() {
    string str = "10101";
    int decimalValue = 0;

    for (char bit : str) {
        decimalValue = (decimalValue << 1) | (bit - '0');
    }

    cout << "Binary Number = " << str << endl;
    cout << "Decimal Value = " << decimalValue << endl;

    return 0;
}