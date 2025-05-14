#include <iostream>
using namespace std;

int main() {
    int n, sum = 0;

    // Prompt user for the number of terms
    cout << "Input number of terms: ";
    cin >> n;

    cout << "The odd numbers are: ";

    // Loop to calculate odd numbers and their sum
    for (int i = 0; i < n; i++) {
        int oddNumber = 2 * i + 1; // Generate the i-th odd number
        cout << oddNumber << " ";
        sum += oddNumber; // Add to the sum
    }

    // Display the sum
    cout << endl;
    cout << "The Sum of odd Natural Numbers up to " << n << " terms: " << sum << endl;

    return 0;
}