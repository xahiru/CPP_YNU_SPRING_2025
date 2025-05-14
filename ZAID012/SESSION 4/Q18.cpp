#include <iostream>
#include <string>
using namespace std;

int main() {
    string input = "101011";
    int decimalValue = stoi(input, nullptr, 2);
    cout << "Decimal Value = " << decimalValue << endl;
    return 0;
}
