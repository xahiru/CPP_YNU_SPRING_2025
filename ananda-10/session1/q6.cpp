#include <iostream>
#include <cmath>  

int main() {
    double principal = 25000, rate = 12, time = 5;

    double amount = principal * pow(1 + rate / 100, time);
    double compoundInterest = amount - principal;
    std::cout << "Compound Interest = " << compoundInterest << std::endl;

    return 0;
}
