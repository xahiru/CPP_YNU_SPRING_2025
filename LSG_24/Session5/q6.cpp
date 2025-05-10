#include <iostream>
#include <cmath>
using namespace std;

double factorial(int n) {
    double fact = 1;
    for (int i = 2; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

double calculateSeries(double x, int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        double term = pow(-1, i) * pow(x, 2*i) / factorial(2*i);
        cout << "term " << i+1 << " value is: " << term << endl;
        sum += term;
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
    
    double sum = calculateSeries(x, n);
    cout << "The sum of the above series is: " << sum;
    return 0;
}