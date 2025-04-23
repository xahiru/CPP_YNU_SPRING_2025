#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double principal = 25000;
    double rate = 12;
    double time = 5;
    
    double compoundInterest = principal * (pow((1 + rate / 100), time) - 1);
    cout << "Compound Interest = " << compoundInterest << endl;

    return 0;
}