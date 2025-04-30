#include <iostream>
#include <cmath>
using namespace std;

int main() {
    string binary = "101011";
    int decimal = 0;

    for (int i = 0; i < binary.length(); i++) {
        decimal += (binary[binary.length() - 1 - i] - '0') * pow(2, i);
    }
    cout << "Decimal Output: " << decimal << endl;
    return 0;
}
