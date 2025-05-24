#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int n;

    cout << "Input the number of Letters (less than 26) in the Pyramid: ";
    cin >> n;

    if (n < 1 || n > 25) {
        cout << "Please enter a number between 1 and 25." << endl;
        return 1;
    }

    for (int i = 1; i <= n; i++) {
        cout << setw((n - i) * 2 + 1);

        for (int j = 0; j < i; j++) {
            cout << char('A' + j) << " ";
        }

        for (int j = i - 2; j >= 0; j--) {
            cout << char('A' + j) << " ";
        }

        cout << endl;
    }

    return 0;
}

