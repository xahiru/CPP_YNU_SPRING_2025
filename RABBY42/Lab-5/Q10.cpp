#include <iostream>
using namespace std;

int main() {
    int n, sum = 0;
    cout << "Input number of terms: ";
    cin >> n;
    cout << "The odd numbers are: ";
    for (int i = 1; i <= n; ++i) {
        int odd = 2*i - 1;
        cout << odd << " ";
        sum += odd;
    }
    cout << "\nThe Sum of odd Natural Numbers upto " << n << " terms: " << sum << endl;
    return 0;
}