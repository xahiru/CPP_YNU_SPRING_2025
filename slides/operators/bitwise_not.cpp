#include <iostream>
using namespace std;

int main() {
    unsigned int x = 1;  // Binary: 0000...0001
    cout << (~x) << endl; // Perform bitwise NOT on x

    x = 5;  // Binary: 0000...0101
    cout << (~x) << endl; // Perform bitwise NOT on x

    return 0;
}