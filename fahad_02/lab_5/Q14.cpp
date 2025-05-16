#include <iostream>
using namespace std;

int main() {
    // Create an array of integers
    int arr[] = {1, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);  // Determine the number of elements in the array

    // Print original array
    cout << "Array: [";
    for (int i = 0; i < n; ++i) {
        cout << arr[i];
        if (i != n - 1) cout << ", ";  // Format the output
    }
    cout << "]" << endl;

    // Double the values using a reference in a range-based for loop
    for (int &num : arr) {
        num *= 2;  // Double the value using reference
    }

    // Print the doubled array
    cout << "Doubled Array: [";
    for (int i = 0; i < n; ++i) {
        cout << arr[i];
        if (i != n - 1) cout << ", ";  // Format the output
    }
    cout << "]" << endl;

    return 0;
}
