#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double X, sum = 0, term;
    int n;

    cout << "Input the value of X: ";
    cin >> X;
    cout << "Input the value for nth term: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        int power = 2 * i;
        
        long long fact = 1;
        for (int j = 1; j <= power; j++) {
            fact *= j;
        }

        term = pow(X, power) / fact;

        if (i % 2 != 0) {
            term = -term;
        }

        cout << "term " << i + 1 << " value is: " << term << endl;

        sum += term;
    }

    cout << "The sum of the above series is: " << sum << endl;

    return 0;
}
