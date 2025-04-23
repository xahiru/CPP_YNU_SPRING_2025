#include <iostream>

// Recursive function to calculate the nth Fibonacci number
int fibonacciRecursive(int n) {
    // Base cases
    if (n <= 1) {
        return n;
    } else {
        // Recursive step: F(n) = F(n-1) + F(n-2)
        return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
    }
}

int main() {
    int n;

    std::cout << "Input a number: ";
    std::cin >> n;

    if (n < 0) {
        std::cout << "Invalid input. Please enter a non-negative integer." << std::endl;
    } else {
        int result = fibonacciRecursive(n);
        std::cout << "The " << n << "th Fibonacci number is: " << result << std::endl;
    }

    return 0;
}