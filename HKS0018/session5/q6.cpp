#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double factorial(int n) {
    double fact = 1;
    for (int i = 1; i <= n; ++i) {
        fact *= i;
    }
    return fact;
}

int main() {
    double x;
    int n;
    
    cout << "Input the value of X: ";
    cin >> x;
    cout << "Input the value for nth term: ";
    cin >> n;
    
    double sum = 0;
    double term;
    
    for (int i = 1; i <= n; ++i) {
        int exponent = 2 * (i - 1);
        term = pow(-1, i - 1) * pow(x, exponent) / factorial(exponent);
        
        cout << "term " << i << " value is: " << term << endl;
        
        sum += term;
    }
    
    cout << "The sum of the above series is: " << sum << endl;
    


    return 0;

}