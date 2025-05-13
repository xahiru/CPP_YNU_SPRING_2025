#include <iostream>
using namespace std;

int main() {
    int n;

    // Input the number of letters for the pyramid
    cout << "Input the number of Letters (less than 26) in the Pyramid: ";
    cin >> n;

    // Check if the number is less than 26
    if (n < 1 || n > 26) {
        cout << "Please enter a number between 1 and 26." << endl;
        return 1;
    }

    // Generate the pyramid pattern
    for (int i = 0; i < n; i++) {
        // Print leading spaces
        for (int j = 0; j < n - i - 1; j++) {
            cout << "  ";
        }

        // Print the left side of the pyramid
        for (int j = 0; j <= i; j++) {
            cout << char('A' + j) << " ";
        }

        // Print the right side of the pyramid
        for (int j = i - 1; j >= 0; j--) {
            cout << char('A' + j) << " ";
        }

        // Move to the next line
        cout << endl;
    }

    return 0;
}