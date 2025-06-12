#include <iostream>
using namespace std;

struct Complex {
    double real, imag;
};

Complex add(Complex c1, Complex c2) {
    Complex res;
    res.real = c1.real + c2.real;
    res.imag = c1.imag + c2.imag;
    return res;
}

int main() {
    Complex c1 = {3, 6}, c2 = {-1, 4};
    Complex res = add(c1, c2);
    cout << res.real << " + " << res.imag << "i";
    return 0;
}