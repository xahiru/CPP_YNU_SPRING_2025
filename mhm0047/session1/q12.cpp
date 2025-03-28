#include <iostream>
using namespace std;

int main() {
    double num1, num2;
    char operation;

    cout << "Enter the first number: ";
    cin >> num1;

    cout << "Enter the second number: ";
    cin >> num2;

    cout << "Enter a for addition, s for subtraction, m for multiplication, d for division: ";
    cin >> operation;

    if (operation == 'a') {
        cout << "Result: " << num1 + num2 << endl;
    } else if (operation == 's') {
        cout << "Result: " << num1 - num2 << endl;
    } else if (operation == 'm') {
        cout << "Result: " << num1 * num2 << endl;
    } else if (operation == 'd') {
        if (num2 != 0) {
            cout << "Result: " << num1 / num2 << endl;
        } else {
            cout << "Error! Division by zero is not allowed." << endl;
        }
    } else {
        cout << "Invalid operation!" << endl;
    }

    return 0;
}