#include <iostream>

using namespace std;

int main() {
    int rows;

    // Input number of rows for the inverted triangle
    cout << "Enter the number of rows for the inverted triangle: ";
    cin >> rows;

    // Loop to print the inverted triangle pattern
    for (int i = rows; i >= 1; --i) {
        // Print leading spaces
        for (int j = 0; j < rows - i; ++j) {
            cout << " ";
        }
        // Print stars
        for (int j = 0; j < (2 * i - 1); ++j) {
            cout << "*";
        }
        // Move to the next line
        cout << endl;
    }

    return 0;
}