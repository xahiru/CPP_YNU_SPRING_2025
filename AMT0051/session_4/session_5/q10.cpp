#include <iostream>
using namespace std;

int main() {
    int n, sum = 0, odd = 1;

    cout << "Input number of terms: ";
    cin >> n;

    cout << "The odd numbers are: ";
    for (int i = 1; i <= n; ++i) {
        cout << odd << " ";
        sum += odd;
        odd += 2;
    }

    cout << "\nThe Sum of odd Natural Numbers upto " << n << " terms: " << sum << endl;

    return 0;
}
