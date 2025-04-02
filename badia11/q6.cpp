#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double principal = 25000, rate = 12, time = 5;
    double compoundInterest = principal * pow((1 + rate / 100), time) - principal;
    cout << "Compound Interest = " << compoundInterest << endl;
    return 0;
}