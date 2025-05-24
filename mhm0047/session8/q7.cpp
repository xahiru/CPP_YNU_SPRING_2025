#include <iostream>
using namespace std;

int main() {
    struct Complex {
        int real, imag;
    };

    Complex c1 = {3, 6}, c2 = {-1, 4};
    Complex sum;

    sum.real = c1.real + c2.real;
    sum.imag = c1.imag + c2.imag;

    cout << sum.real << " + " << sum.imag << "i";
    return 0;
}
