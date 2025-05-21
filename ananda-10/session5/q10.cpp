#include <iostream>
using namespace std;

int main() {
    int n, sum = 0;

    cout << "Input number of terms: ";
    cin >> n;

    cout << "The odd numbers are: ";
    for (int i = 1, count = 0; count < n; i += 2) {
        cout << i << " ";
        sum += i;
        count++;
    }

    cout << "\nThe Sum of odd Natural Numbers upto " << n << " terms: " << sum << endl;

    return 0;
}

