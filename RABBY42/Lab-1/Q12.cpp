#include <iostream>
using namespace std;

int main() {
    char operation;
    double num1, num2, result;

    
    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;


    cout << "\nChoose operation:\n";
    cout << "a for addition\n";
    cout << "s for subtraction\n";
    cout << "m for multiplication\n";
    cout << "d for division\n";
    cout << "Enter your choice: ";
    cin >> operation;


    switch(operation) {
        case 'a':
            result = num1 + num2;
            cout << "Result: " << result;
            break;
        case 's':
            result = num1 - num2;
            cout << "Result: " << result;
            break;
        case 'm':
            result = num1 * num2;
            cout << "Result: " << result;
            break;
        case 'd':
            if (num2 != 0) {
                result = num1 / num2;
                cout << "Result: " << result;
            } else {
                cout << "Error! Division by zero is not allowed.";
            }
            break;
        default:
            cout << "Invalid operation selected!";
    }

    return 0;
}