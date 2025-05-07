#include <iostream>
#include <cmath>

double sumOfSeries(double x, int n) {
    double sum = 1.0; // Starting with term 1
    for (int i = 1; i <= n; ++i) {
        double term = (i % 2 == 0 ? -1 : 1) * (pow(x, 2 * i) / tgamma(2 * i + 1));
        sum += term;
        std::cout << "term " << i << " value is: " << term << std::endl;
    }
    return sum;
}

int main() {
    double x;
    int n;
    std::cout << "Input the value of X: ";
    std::cin >> x;
    std::cout << "Input the value for nth term: ";
    std::cin >> n;
    double result = sumOfSeries(x, n);
    std::cout << "The sum of the above series is: " << result << std::endl;
    return 0;
}
