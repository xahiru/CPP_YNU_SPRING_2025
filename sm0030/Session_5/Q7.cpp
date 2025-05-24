#include <iostream>
#include <cmath>

// Function to calculate factorial
long double factorial(int n) {
    long double fact = 1.0;
    for (int i = 1; i <= n; ++i) {
        fact *= i;
    }
    return fact;
}

int main() {
    double X;
    int n_terms;

    std::cout << "Input the value of X: ";
    std::cin >> X;
    std::cout << "Input the value for nth term: ";
    std::cin >> n_terms;

    double sum = 0.0;
    for (int i = 0; i < n_terms; ++i) {
        double term_value;
        if (i % 2 == 0) { // Positive term (1, X^4/4!, ...)
            term_value = std::pow(X, 2 * i) / factorial(2 * i);
        } else { // Negative term (-X^2/2!, ...)
            term_value = -std::pow(X, 2 * i) / factorial(2 * i);
        }
        sum += term_value;
        std::cout << "term " << i + 1 << " value is: " << term_value << std::endl;
    }

    std::cout << "The sum of the above series is: " << sum << std::endl;

    return 0;
}