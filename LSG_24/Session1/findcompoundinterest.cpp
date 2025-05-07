#include <iostream>
#include <cmath> // For pow() function
#include <iomanip> // For setprecision()
using namespace std;

int main() {
    double principal, rate, time, compoundInterest;

    // Input values
    cout << "Enter principal amount: ";
    cin >> principal;
    cout << "Enter annual interest rate (in %): ";
    cin >> rate;
    cout << "Enter time (in years): ";
    cin >> time;

    // Convert rate from percentage to decimal
    rate = rate / 100;

    // Calculate compound interest
    compoundInterest = principal * pow((1 + rate), time) - principal;

    // Display result with 2 decimal places
    cout << fixed << setprecision(2);
    cout << "Compound Interest = " << compoundInterest;

    return 0;
}