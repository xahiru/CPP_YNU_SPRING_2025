#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double principal, rate, time, ci;
    cout << "Enter Principal: ";
    cin >> principal;
    cout << "Enter Rate (%): ";
    cin >> rate;
    cout << "Enter Time (years): ";
    cin >> time;

    ci = principal * pow(1 + rate / 100, time) - principal;

    cout << "Compound Interest = " << ci << endl;
    return 0;
}