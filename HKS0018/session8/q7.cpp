#include <iostream>

using namespace std;

struct Complex {
    float real;
    float imaginary;
};

Complex add(Complex c1, Complex c2) {
    Complex result;
    result.real = c1.real + c2.real;
    result.imaginary = c1.imaginary + c2.imaginary;
    return result;
}

int main() {
    Complex c1 = {3.0, 6.0};  // 3 + 6i
    Complex c2 = {-1.0, 4.0}; // -1 + 4i

    Complex sum = add(c1, c2);

    cout << sum.real << " + " << sum.imaginary << "i" << endl;
    
    return 0;
}