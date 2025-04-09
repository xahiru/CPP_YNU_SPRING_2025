#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    double principal = 25000;
    double rate = 12; 
    double time = 5;

    double compoundInterest = principal * (pow((1 + rate / 100), time)) - principal;

    std::cout << std::fixed << std::setprecision(2); 
    std::cout << "Compound Interest = " << compoundInterest << std::endl;

    return 0;
}