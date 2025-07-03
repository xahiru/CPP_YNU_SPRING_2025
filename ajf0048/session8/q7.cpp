#include <iostream>

struct Complex {
    double real, imag;
};

Complex add(const Complex& c1, const Complex& c2) {
    return {c1.real + c2.real, c1.imag + c2.imag};
}

int main() {
    Complex c1 = {3, 6};
    Complex c2 = {-1, 4};
    Complex result = add(c1, c2);
    std::cout << "Result: " << result.real << " + " << result.imag << "i" << std::endl;
    return 0;
}