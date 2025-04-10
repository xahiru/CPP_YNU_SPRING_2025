#include <iostream>
using namespace std;

int main() {
    double price, rate, time, compound_interest;
    cout << "Enter the principal amount: ";
    cin >> price;
    cout << "Enter the rate of interest: ";
    cin >> rate;
    cout << "Enter the time period in years: ";
    cin >> time;
    compound_interest = (price * rate * time) / 100;
    cout << "The simple interest is: " << compound_interest << endl;
    cout << "The total amount after interest is: " << price + compound_interest << endl;
    return 0;
}