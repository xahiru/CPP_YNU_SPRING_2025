#include <iostream>
#include <cmath> // For pow function
#include <iomanip> // For setting precision

using namespace std;

int main() {
    double principal, rate, time, compoundInterest;

    // Input values
    cout << "Enter the Principal amount: ";
    cin >> principal;
    cout << "Enter the Rate of Interest (in %): ";
    cin >> rate;
    cout << "Enter the Time (in years): ";
    cin >> time;

    // Calculate compound interest
    compoundInterest = principal * (pow((1 + rate / 100), time) - 1);

    // Output the result with 2 decimal places
    cout << fixed << setprecision(2);
    cout << "Compound Interest = " << compoundInterest << endl;

    return 0;
}