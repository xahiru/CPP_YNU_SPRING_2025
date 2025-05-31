#include <iostream>

// Recursive function to find the nth Fibonacci number
int fibonacci(int n) {
    if (n == 0) return 0;         // base case
    if (n == 1) return 1;         // base case
    return fibonacci(n - 1) + fibonacci(n - 2);  // recursive call
}

int main() {
    int num;

    std::cout << "Input a number: ";
    std::cin >> num;

    int result = fibonacci(num);
    std::cout << "The " << num << "th Fibonacci number is: " << result << std::endl;

    return 0;
}
