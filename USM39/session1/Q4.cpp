#include <iostream>
using namespace std;

int main() {
    int a, b, temp;

    // I am doing by myself ahmad zahir
    cout << "Enter the value of a: ";
    cin >> a;
    cout << "Enter the value of b: ";
    cin >> b;

    
    temp = a;
    a = b;
    b = temp;

    
    cout << "After swapping:" << endl;
    cout << "a = " << a << ", b = " << b << endl;

    return 0;
}