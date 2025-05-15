#include <iostream>
#include <cmath>   // For pow()
#include <iomanip> // For setting precision

using namespace std;

// Function to calculate factorial
long long factorial(int n) {
    long long fact = 1;
    for (int i = 2; i <= n; ++i)
        fact *= i;
    return fact;
}

int main() {
    double x;
    int n;

    cout << "Input the value of X: ";
    cin >> x;

    cout << "Input the value for nth term: ";
    cin >> n;

    double sum = 0.0;
    int exponent = 0;

    cout << fixed << setprecision(4); // Output with 4 decimal places

    for (int i = 1; i <= n; ++i) {
        double term = pow(x, exponent) / factorial(exponent);

        // Alternate signs: +, -, +, -, ...
        if (i % 2 == 0)
            term *= -1;

        sum += term;

        cout << "term " << i << " value is: " << term << endl;

        exponent += 2;
    }

    cout << "The sum of the above series is: " << sum << endl;

    return 0;
}
