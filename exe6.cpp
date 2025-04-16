#include <iostream>
#include <cmath> 
using namespace std;

int main() {

    double principal, rate, time, compoundInterest, amount;

    cout << "Enter the principal amount: ";
    cin >> principal;
    cout << "Enter the rate of interest: ";
    cin >> rate;
    cout << "Enter the time in years: ";
    cin >> time;

    amount = principal * pow((1 + rate / 100), time);
    compoundInterest = amount - principal;

    cout << "Compound Interest = " << compoundInterest << endl;

    return 0;
}