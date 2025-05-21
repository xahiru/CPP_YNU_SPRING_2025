#include<iostream>
using namespace std;

struct Complex {
    int real, imag;
};

Complex add(Complex c1, Complex c2) {
    Complex res;
    res.real = c1.real + c2.real;
    res.imag = c1.imag + c2.imag;
    return res;
}

int main() {
    Complex c1 = {3, 6}, c2 = {-1, 4};
    Complex result = add(c1, c2);
    cout << result.real << " + " << result.imag << "i" << endl;
    return 0;
}
