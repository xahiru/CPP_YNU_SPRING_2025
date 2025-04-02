#include <iostream>
#include <cmath>

int main() {
    double principal, rate, time, compoundInterest;

    std::cout << "Enter Principal amount: ";
    std::cin >> principal;

    std::cout << "Enter Rate of Interest (%): ";
    std::cin >> rate;

    std::cout << "Enter Time (in years): ";
    std::cin >> time;

    compoundInterest = principal * pow((1 + rate / 100), time) - principal;

    std::cout << "Compound Interest = " << compoundInterest << std::endl;

    return 0;
}