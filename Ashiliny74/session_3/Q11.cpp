#include <iostream>

using namespace std;

// Recursive function to calculate the nth Fibonacci number
int fibonacci(int n) {
    // Base cases
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    }
    // Recursive case
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n;

    // Input from the user
    cout << "Input a number: ";
    cin >> n;

    // Calculate the nth Fibonacci number
    int result = fibonacci(n);

    // Output the result
    cout << "The " << n << "th Fibonacci number is: " << result << endl;

    return 0;
}