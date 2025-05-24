#include <iostream>
using namespace std;

struct Complex {
    double real;
    double imag;
};

Complex add(Complex c1, Complex c2) {
    Complex result;
    result.real = c1.real + c2.real;
    result.imag = c1.imag + c2.imag;
    return result;
}

int main() {
    Complex c1 = {3, 6};
    Complex c2 = {-1, 4};
    
    Complex result = add(c1, c2);
    cout << result.real << " + " << result.imag << "i" << endl;
    return 0;
}