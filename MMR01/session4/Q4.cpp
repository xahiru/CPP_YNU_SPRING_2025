#include <iostream>
using namespace std;

void swapNumbers(int *x, int *y) {
    int temp = *x;  
    *x = *y;        // Assign the value pointed to by y to x's location
    *y = temp;      // Assign the original x value to y's location
}

int main() {
    int a, b;
    
    cout << "Enter two numbers: ";
    cin >> a >> b;
    
    cout << "Before swapping: " << a << " " << b << endl;
    swapNumbers(&a, &b);  // Pass the addresses of a and b
    cout << "After swapping: " << a << " " << b << endl;
    
    return 0;
}