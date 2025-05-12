#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double X, sum = 0;
    int n;
    cout << "Input the value of X: ";
    cin >> X;
    cout << "Input the value for nth term: ";
    cin >> n;
    
    for (int k = 1; k <= n; ++k) {
        int exponent = 2 * (k - 1);
        double sign = (k % 2 == 1) ? 1 : -1;
        double numerator = pow(X, exponent);
        double denom = 1;
        for (int i = 1; i <= exponent; ++i) denom *= i;
        double term = sign * numerator / denom;
        sum += term;
        cout << "term " << k << " value is: " << term << endl;
    }
    cout << "The sum of the above series is: " << sum << endl;
    return 0;
}