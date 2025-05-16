#include <iostream>
#include <cmath>

using namespace std;

double factorial(int n) {
    double fact = 1.0;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

double sumOfSeries(double X, int n) {
    double sum = 0.0;
    for (int i = 0; i < n; i++) {

        double power = pow(X, 2 * i);

        double fact = factorial(2 * i);

        double term = pow(-1, i) * (power / fact);

        cout << "term " << i + 1 << " value is: " << term << endl;

        sum += term;
    }
    
    return sum;
}

int main() {
    double X;
    int n;

    cout << "Input the value of X: ";
    cin >> X;
    cout << "Input the value for nth term: ";
    cin >> n;

    double sum = sumOfSeries(X, n);

    cout << "The sum of the above series is: " << sum << endl;

    return 0;
}