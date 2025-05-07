#include <iostream>
using namespace std;

// Recursive function to calculate nth Fibonacci number
int fibonacci(int n) {
    // Base cases
    if (n == 0) return 0;
    if (n == 1) return 1;
    
    // Recursive case
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n;
    
    cout << "Input a number: ";
    cin >> n;
    
    // Validate input
    if (n < 0) {
        cout << "Please enter a non-negative integer." << endl;
        return 1;
    }
    
    cout << "The " << n;
    // Handle ordinal suffix (1st, 2nd, 3rd, etc.)
    if (n % 100 >= 11 && n % 100 <= 13) {
        cout << "th";
    } else {
        switch (n % 10) {
            case 1: cout << "st"; break;
            case 2: cout << "nd"; break;
            case 3: cout << "rd"; break;
            default: cout << "th"; break;
        }
    }
    
    cout << " Fibonacci number is: " << fibonacci(n) << endl;
    
    return 0;
}