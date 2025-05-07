#include <iostream>
using namespace std;

void swapWithPointers(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main() {
    int a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;

    swapWithPointers(&a, &b);

    cout << "After swapping: " << a << " " << b << endl;

    return 0;
}