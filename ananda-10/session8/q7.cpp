#include <iostream>
using namespace std;

struct Complex {
    int real;
    int imag;
};

Complex add(Complex c1, Complex c2) {
    Complex result;
    result.real = c1.real + c2.real;
    result.imag = c1.imag + c2.imag;
    return result;
}

void printComplex(Complex c) {
    cout << c.real << " + " << c.imag << "i" << endl;
}

int main() {
    
    Complex c1 = {3, 6};
    Complex c2 = {-1, 4};

    Complex sum = add(c1, c2);

    cout << "Sum: ";
    printComplex(sum);  

    return 0;
}

