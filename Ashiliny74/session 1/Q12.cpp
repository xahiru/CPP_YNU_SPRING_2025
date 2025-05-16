#include <iostream>

using namespace std;

int main() {
    double num1, num2;
    char operation;

    // Input two numbers
    cout << "Enter the first number: ";
    cin >> num1;
    cout << "Enter the second number: ";
    cin >> num2;

    // Input the operation
    cout << "Enter 'a' for addition,\n"
         << "'s' for subtraction,\n"
         << "'m' for multiplication,\n"
         << "'d' for division: ";
    cin >> operation;

    // Perform the operation based on user input
    switch (operation) {
        case 'a':
            cout << "Result: " << (num1 + num2) << endl;
            break;
        case 's':
            cout << "Result: " << (num1 - num2) << endl;
            break;
        case 'm':
            cout << "Result: " << (num1 * num2) << endl;
            break;
        case 'd':
            if (num2 != 0) {
                cout << "Result: " << (num1 / num2) << endl;
            } else {
                cout << "Error: Division by zero is not allowed." << endl;
            }
            break;
        default:
            cout << "Invalid operation selected." << endl;
            break;
    }

    return 0;
}