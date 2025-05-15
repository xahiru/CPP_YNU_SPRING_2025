#include <iostream>
#include <cmath>
using namespace std;

long double factorial(int n) {
    if (n == 0 || n == 1) return 1;
    return n * factorial(n - 1);
}

int main() {
    double X;
    int n;
    
    cout << "Input the value of X: ";
    cin >> X;
    cout << "Input the value for nth term: ";
    cin >> n;
    
    double sum = 0;
    for (int i = 0; i < n; i++) {
        int exponent = 2 * i;
        double term = pow(-1, i) * pow(X, exponent) / factorial(exponent);
        cout << "term " << i+1 << " value is: " << term << endl;
        sum += term;
    }
    
    cout << "The sum of the above series is: " << sum << endl;
    return 0;
}
