#include <iostream>
using namespace std;

int main() {
    int x = 33;  // Binary: 0000...100001
    cout << (x >> 1) << endl;  // Shift right by 1
    cout << (x >> 2) << endl;  // Shift right by 2

    int y = 4;  // Binary: 0000...0100
    int z = (x >> y);          // Shift right by 4
    cout << z;                 // Output the result

    return 0;
}