#include <iostream>
using namespace std;

int main() {
    // Initialize variables
    int a = 10;
    int b = 250;

    // Display initial values
    cout << "Before swapping: " << endl;
    cout << "a = " << a << ", b = " << b << endl;

    // Swap the values using a temporary variable
    int temp = a; // Store the value of a in temp
    a = b;        // Assign the value of b to a
    b = temp;    // Assign the value of temp (original a) to b

    // Display swapped values
    cout << "After swapping: " << endl;
    cout << "a = " << a << ", b = " << b << endl;

    return 0;
}