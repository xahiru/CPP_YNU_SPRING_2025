#include <iostream>
using namespace std;

int main() {
    // Given array with a decimal
    double arr[] = {5, 4, 9, 12.8};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Initialize the largest with the integer part of the first element
    int largest = static_cast<int>(arr[0]);

    // Loop through the array
    for (int i = 1; i < n; i++) {
        int current = static_cast<int>(arr[i]); // Convert to int (truncates decimal part)
        if (current > largest) {
            largest = current;
        }
    }

    // Output the result
    cout << "---------------------------------------" << endl;
    cout << "The largest integer is: " << largest << endl;

    return 0;
}
