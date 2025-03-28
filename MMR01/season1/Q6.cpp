#include <iostream>
#include <cmath>  // Required for pow() function
using namespace std;

int main() {
    double principal, rate, time, amount, compoundInterest;

    // ask user enter principal amount
    cout << "Enter the principal amount : ";
    cin >> principal;
    // ask user enter interest rate
    cout << "Enter the annual interest rate: ";
    cin >> rate;
    //ask user enter time
    cout << "Enter the time period : ";
    cin >> time;

    // Calculate compound interest
    amount = principal * pow(1 + (rate / 100), time);
    compoundInterest = amount - principal;

    // Display the result
    cout << "\n--- Results ---" << endl;
    cout << "Principal : " << principal << endl;
    cout << "Rate : " << rate << "%" << endl;
    cout << "Time : " << time << " years" << endl;
    cout << "Final Amount : " << amount << endl;
    cout << "Compound Interest : " << compoundInterest << endl;

    return 0;
}