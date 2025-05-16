#include <iostream>
using namespace std;

struct Complex {
    int real, imag;
};

Complex add(Complex a, Complex b) {
    Complex result;
    result.real = a.real + b.real;
    result.imag = a.imag + b.imag;
    return result;
}

int main() {
    Complex c1 = {3, 6};
    Complex c2 = {-1, 4};
    Complex sum = add(c1, c2);
    cout << sum.real << " + " << sum.imag << "i" << endl;
    return 0;
}