#include <iostream>
#include <iomanip> // For setting the width of spaces

using namespace std;

int main() {
    int n;

    // Input the number of letters in the pyramid
    cout << "Input the number of Letters (less than 26) in the Pyramid: ";
    cin >> n;

    // Outer loop for each row
    for (int i = 1; i <= n; ++i) {
        // Print spaces for alignment
        cout << setw(n - i + 1);

        // Print ascending letters (A to the i-th letter)
        for (char ch = 'A'; ch < 'A' + i; ++ch) {
            cout << ch << " ";
        }

        // Print descending letters (i-1-th letter back to A)
        for (char ch = 'A' + i - 2; ch >= 'A'; --ch) {
            cout << ch << " ";
        }

        // Move to the next line after each row
        cout << endl;
    }

    return 0;
}
