#include <iostream>
using namespace std;

int main() {
    int a, b, temp;
    cout << "Enter the value of a: ";
    cin >> a; 
    cout << "Enter the value of b: ";
    cin >> b;

    cout << "Before swapping: a = " << a << ", b = " << b << endl;
    temp = a; 
    a = b;    
    b = temp; 
    cout << "After swapping: a = " << a << ", b = " << b << endl;

    return 0; 
}