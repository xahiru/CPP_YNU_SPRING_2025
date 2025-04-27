#include <iostream>
using namespace std;

int main() {
    int number;
    
    cout << "Enter an integer: ";
    cin >> number;
    
    if (number % 2 == 0) {
        cout << number << " is Even Number";
    } else {
        cout << number << " is Odd Number";
    }
    
    return 0;
}