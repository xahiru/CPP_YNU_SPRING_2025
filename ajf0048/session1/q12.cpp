#include <iostream>
using namespace std;

int main() {
    int num1, num2;
    char operation;
    cout << "Enter the Number: ";
    cin >> num1 >> num2;
    cout << "Enter a for addition, s for subtraction, m for multiplication, d for division: ";
    cin >> operation;
    switch (operation) {
        case 'a':
            cout << num1 << " + " << num2 << " = " << (num1 + num2) << endl;
            break;
        case 's':
            cout << num1 << " - " << num2 << " = " << (num1 - num2) << endl;
            break;
        case 'm':
            cout << num1 << " * " << num2 << " = " << (num1 * num2) << endl;
            break;
        case 'd':
            if (num2 != 0)
                cout << num1 << " / " << num2 << " = " << (static_cast<double>(num1) / num2) << endl;
            else
                cout << "Division by zero is not allowed." << endl;
            break;
        default:
            cout << "Invalid operation." << endl;
    }
    return 0;
}