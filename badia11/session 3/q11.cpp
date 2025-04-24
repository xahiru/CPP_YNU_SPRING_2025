#include <iostream>

int fibonacci(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int input;

    for (int i : {1, 9, 14}) {
        std::cout << "Input a number: " << i << std::endl;
        std::cout << "The " << i << "th Fibonacci number is: " << fibonacci(i) << std::endl;
    }

    return 0;
}
