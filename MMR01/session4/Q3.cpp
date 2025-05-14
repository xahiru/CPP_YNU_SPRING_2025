#include <iostream>
using namespace std;

void swapNumbers(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}

int main() {
    int a, b;
    
    cout << "Enter two numbers: ";
    cin >> a >> b;
    
    cout << "Before swapping: " << a << " " << b << endl;
    swapNumbers(a, b);
    cout << "After swapping: " << a << " " << b << endl;
    
    return 0;
}