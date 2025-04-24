#include <iostream>
using namespace std;

int main() {
    int a = 5, b = 10;

    cout << "Before swapping: a = " << a << ", b = " << b << endl;

    a = a + b;  // a = 15 (5 + 10)
    b = a - b;  // b = 5 (15 - 10)
    a = a - b;  // a = 10 (15 - 5)

    cout << "After swapping: a = " << a << ", b = " << b << endl;

    return 0;
}