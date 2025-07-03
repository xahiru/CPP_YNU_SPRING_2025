#include <iostream>
using namespace std;

// Structure to represent complex numbers
struct Complex {
    double real;
    double imag;
};

// Function to add two complex numbers
Complex add(Complex c1, Complex c2) {
    Complex result;
    result.real = c1.real + c2.real;
    result.imag = c1.imag + c2.imag;
    return result;
}

// Function to print complex numbers in a+bi format
void printComplex(Complex c) {
    cout << c.real;
    if (c.imag >= 0) {
        cout << " + " << c.imag << "i";
    } else {
        cout << " - " << -c.imag << "i";
    }
    cout << endl;
}

int main() {
    // Example 1
    Complex c1 = {3, 6};
    Complex c2 = {-1, 4};
    Complex sum = add(c1, c2);
    cout << "Example 1: ";
    printComplex(sum);  // Output: 2 + 10i

    // Example 2
    Complex c3 = {5, -3};
    Complex c4 = {2, 7};
    sum = add(c3, c4);
    cout << "Example 2: ";
    printComplex(sum);  // Output: 7 + 4i

    // Example 3
    Complex c5 = {-4, -2};
    Complex c6 = {1, -5};
    sum = add(c5, c6);
    cout << "Example 3: ";
    printComplex(sum);  // Output: -3 - 7i

    return 0;
}