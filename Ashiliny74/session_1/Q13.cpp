#include <iostream>

using namespace std;

// Function to calculate factorial iteratively
unsigned long long factorialIterative(int n) {
    unsigned long long result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

// Function to calculate factorial recursively
unsigned long long factorialRecursive(int n) {
    if (n <= 1) {
        return 1; // Base case
    }
    return n * factorialRecursive(n - 1); // Recursive case
}

int main() {
    int number;

    // Input number
    cout << "Enter a non-negative integer: ";
    cin >> number;

    if (number < 0) {
        cout << "Factorial is not defined for negative numbers." << endl;
    } else {
        // Calculate factorial using iterative method
        unsigned long long iterativeResult = factorialIterative(number);
        cout << "Factorial of " << number << " (iterative) is: " << iterativeResult << endl;

        // Calculate factorial using recursive method
        unsigned long long recursiveResult = factorialRecursive(number);
        cout << "Factorial of " << number << " (recursive) is: " << recursiveResult << endl;
    }

    return 0;
}