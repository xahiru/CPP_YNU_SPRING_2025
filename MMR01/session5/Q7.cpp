#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// Function to calculate factorial
long double factorial(int n) {
    if (n == 0 || n == 1)
        return 1;
    return n * factorial(n - 1);
}

// Function to calculate the sum of series
void calculateSeries(double x, int n) {
    double sum = 0;
    double term;
    int power = 0;
    
    cout << fixed << setprecision(4); // Set precision to 4 decimal places
    
    for (int i = 1; i <= n; i++) {
        // Calculate each term
        term = pow(-1, i+1) * pow(x, power) / factorial(power);
        
        // Print current term
        cout << "term " << i << " value is: " << term << endl;
        
        // Add to sum
        sum += term;
        
        // Increment power by 2 for next term
        power += 2;
    }
    
    // Print final sum
    cout << "The sum of the above series is: " << sum << endl;
}

int main() {
    double x;
    int n;
    
    cout << "Input the value of X: ";
    cin >> x;
    cout << "Input the value for nth term: ";
    cin >> n;
    
    calculateSeries(x, n);
    
    return 0;
}