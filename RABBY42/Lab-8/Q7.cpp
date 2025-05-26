#include <iostream>
using namespace std;

struct Complex { double real, imaginary; };

Complex add(Complex a, Complex b) {
    return {a.real + b.real, a.imaginary + b.imaginary};
}

// Example usage in main (not required for submission)
int main() {
    Complex c1, c2;
    cin >> c1.real >> c1.imaginary >> c2.real >> c2.imaginary;
    Complex res = add(c1, c2);
    cout << res.real << " + " << res.imaginary << "i";
}