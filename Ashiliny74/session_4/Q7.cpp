#include <iostream>
#include <cmath>
using namespace std;

// Function to calculate factorial
double factorial(int n) {
    double fact = 1.0;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

// Function to calculate the sum of the series
double sumOfSeries(double x, int n) {
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        int power = 2 * i; // even powers
        double term = (pow(x, power) / factorial(power)) * (i % 2 == 0 ? 1 : -1);
        cout << "term " << (i + 1) << " value is: " << term << endl;
        sum += term;
    }
    return sum;
}

int main() {
    double x;
    int n;

    // Input values for X and n
    cout << "Input the value of X: ";
    cin >> x;
    cout << "Input the value for nth term: ";
    cin >> n;

    // Calculate the sum of the series
    double result = sumOfSeries(x, n);
    cout << "The sum of the above series is: " << result << endl;

    return 0;
}