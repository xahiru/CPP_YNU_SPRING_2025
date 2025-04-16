#include <iostream>
using namespace std;

int main() {

    double num1, num2;
    char operation;

    cout << "Enter the first number: ";
    cin >> num1;
    cout << "Enter the second number: ";
    cin >> num2;

    cout << "Enter 'a' for addition, 's' for subtraction, 'm' for multiplication, 'd' for division: ";
    cin >> operation;

    
    switch (operation) {
        case 'a': 
            cout << "Result: " << num1 + num2 << endl;
            break;
        case 's': 
            cout << "Result: " << num1 - num2 << endl;
            break;
        case 'm': 
            cout << "Result: " << num1 * num2 << endl;
            break;
        case 'd':
            if (num2 != 0) {
                cout << "Result: " << num1 / num2 << endl;
            } else {
                cout << "Error: Division by zero is not allowed!" << endl;
            }
            break;
        default:
            cout << "Invalid operation!" << endl;
    }

    return 0;
}
