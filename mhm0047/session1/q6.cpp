#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double principal, rate, time, compoundInterest, amount;

    cout << "Enter the Principal amount: ";
    cin >> principal;

    cout << "Enter the Rate of Interest (in percentage): ";
    cin >> rate;

    cout << "Enter the Time (in years): ";
    cin >> time;

    amount = principal * pow((1 + rate / 100), time);

    compoundInterest = amount - principal;

    cout << "Compound Interest = " << compoundInterest << endl;

    return 0;
}