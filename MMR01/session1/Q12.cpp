#include <iostream>
using namespace std;

int main() {
    char uniqcal;
    double num1, num2;
    //ask user to input number and operation
    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;
    cout << "Enter operation from this four (+, -, *, /): ";
    cin >> uniqcal;
    //arithmetic operations (if-else if-else logic)
    if (uniqcal == '+') {
        cout << "Result: " << num1 + num2;
    } 
    else if (uniqcal == '-') {
        cout << "Result: " << num1 - num2;
    } 
    else if (uniqcal == '*') {
        cout << "Result: " << num1 * num2;
    } 
    else if (uniqcal == '/') {
        if (num2 != 0) {
            cout << "Result: " << num1 / num2;
        } else {
            cout << "Error! Division by zero!";
        }
    } 
    else {
        cout << "Invalid operator!";
    }

    return 0;
}