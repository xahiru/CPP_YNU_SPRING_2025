#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
    double principal, rate, time, compoundInterest;


    cout << "Enter principal amount: ";
    cin >> principal;

    cout << "Enter annual interest rate (in %): ";
    cin >> rate;

    cout << "Enter time period (in years): ";
    cin >> time;


    rate = rate / 100;


    compoundInterest = principal * pow((1 + rate), time) - principal;

    
    cout << fixed << setprecision(2);
    cout << "\nCompound Interest = " << compoundInterest << endl;

    return 0;
}