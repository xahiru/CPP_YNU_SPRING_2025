#include <iostream>
using namespace std;

void swapValue(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int a, b;

    cout << "Enter two integers:\n";
    cin >> a >> b;

    cout << "Before swap: a = " << a << ", b = " << b << endl;

    swapValue(&a, &b);

    cout << "After swap:  a = " << a << ", b = " << b << endl;

    return 0;
}
