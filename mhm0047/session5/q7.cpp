#include <iostream>
using namespace std;


double computeFactorial(int num) {
    double result = 1;
    for (int i = 2; i <= num; ++i) {
        result *= i;
    }
    return result;
}

double calculateSeries(double x, int terms) {
    double total = 0;
    int sign = 1;

    for (int i = 0; i < terms; ++i) {
        int exp = 2 * i;
        double numerator = 1;
        for (int j = 0; j < exp; ++j) {
            numerator *= x;
        }

        double denominator = computeFactorial(exp);
        double value = sign * numerator / denominator;

        cout << "term " << i + 1 << " value is: " << value << endl;
        total += value;
        sign *= -1; 
    }

    return total;
}

int main() {
    double x;
    int n;

    cout << "Input the value of X: ";
    cin >> x;
    cout << "Input the value for nth term: ";
    cin >> n;

    double result = calculateSeries(x, n);
    cout << "The sum of the above series is: " << result << endl;

    return 0;
}
