#include <iostream>
#include <cmath> // For floor if needed
using namespace std;

int main() {
    // Original array with one float-like value
    double arr[] = {5, 4, 9, 12.8};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Initialize largest with the integer part of the first element
    int largest = static_cast<int>(arr[0]);

    // Loop through the array
    for (int i = 1; i < n; i++) {
        int current = static_cast<int>(arr[i]); // Convert to int
        if (current > largest) {
            largest = current;
        }
    }

    cout << "The largest integer is: " << largest << endl;
    return 0;
}
