#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Input number of terms: ";
    cin >> n;

    int sum = 0;
    cout << "The odd numbers are: ";
    for (int i = 0; i < n; ++i) {
        int odd = 2 * i + 1;
        cout << odd << " ";
        sum += odd;
    }
    cout << "\nThe Sum of odd Natural Numbers up to " << n << " terms: " << sum << endl;
    return 0;
}