#include <iostream>
using namespace std;

int main() {
    int n;

    // Input the number of terms
    cout << "Enter n: ";
    cin >> n;

    // Dynamically allocate an array to store squares of first n natural numbers
    int* squares = new int[n];

    // Calculate the squares and store them in the array
    for (int i = 0; i < n; ++i) {
        squares[i] = (i + 1) * (i + 1);  // Square of (i + 1)
    }

    // Display the squares
    cout << "Squares: ";
    for (int i = 0; i < n; ++i) {
        cout << squares[i] << " ";
    }
    cout << endl;

    // Deallocate the dynamically allocated array
    delete[] squares;

    return 0;
}

