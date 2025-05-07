#include <iostream>
using namespace std;


void swapValues(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}

int main() {
    int a, b;

    cout << "Enter two integers (a and b): ";
    cin >> a >> b;

    swapValues(a, b);

    cout << "Output: " << a << " " << b << endl;

    return 0;
}
