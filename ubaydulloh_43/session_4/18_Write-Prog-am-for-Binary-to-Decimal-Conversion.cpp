#include <iostream>
#include <string>
using namespace std;

int main() {
    string binaryStr = "101011";
    int decimalValue = 0;

    for (char bit : binaryStr) {
        decimalValue = (decimalValue << 1) | (bit - '0');
    }

    cout << "Input: " << binaryStr << endl;
    cout << "Output: " << decimalValue << endl;

    return 0;
}