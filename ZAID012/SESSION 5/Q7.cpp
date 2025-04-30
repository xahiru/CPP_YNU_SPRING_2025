#include <iostream>
#include <cmath>
using namespace std;

double calculateSum(double x, int n) {
    double sum = 1.0;
    for (int i = 1; i <= n; ++i) {
        double term = pow(-1, i) * pow(x, 2 * i) / tgamma(2 * i + 1);
        sum += term;
        cout << "Term " << i << " value is: " << term << endl;
    }
    return sum;
}

int main() {
    double x;
    int n;
    cout << "Input the value of X: ";
    cin >> x;
    cout << "Input the value for nth term: ";
    cin >> n;

    double result = calculateSum(x, n);
    cout << "The sum of the above series is: " << result << endl;
    return 0;
}