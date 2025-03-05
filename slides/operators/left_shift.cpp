#include <iostream>
using namespace std;

int main() {
    int x = 3;  // Binary: 0000...0011
    cout << (x << 1) << endl;  // Shift left by 1
    cout << (x << 2) << endl;  // Shift left by 2

    int y = 4;  // Binary: 0000...0100
    int z = (x << y);          // Shift left by 4
    cout << z;                 // Output the result

    return 0;
}