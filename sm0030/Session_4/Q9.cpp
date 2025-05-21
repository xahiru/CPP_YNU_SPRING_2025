#include <iostream>
using namespace std;

const int MAX_RANGE = 1000001; // Adjust for expected input range

bool canFormConsecutive(int* arr, int size) {
    if (size == 0) return true; // Empty array is consecutive

    // Find min and max, and check for negative numbers
    int min_val = arr[0], max_val = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < min_val) min_val = arr[i];
        if (arr[i] > max_val) max_val = arr[i];
    }

    // Check if numbers are within valid range (non-negative, <= MAX_RANGE)
    if (min_val < 0 || max_val >= MAX_RANGE) {
        cout << "Error: Numbers must be non-negative and less than " << MAX_RANGE << endl;
        return false;
    }

    // Check for duplicates using a boolean array
    bool* seen = new bool[MAX_RANGE](); // Initialize to false
    for (int i = 0; i < size; i++) {
        if (seen[arr[i]]) {
            delete[] seen;
            return false; // Duplicate found
        }
        seen[arr[i]] = true;
    }

    // Clean up
    delete[] seen;

    // Check if max - min equals size - 1
    return (max_val - min_val) == (size - 1);
}

int main() {
    int size;
    cout << "Enter number of elements: ";
    cin >> size;

    // Dynamically allocate array
    int* arr = new int[size];
    
    // Input elements
    cout << "Enter " << size << " elements: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    // Print array
    cout << "Array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    // Check and output result
    cout << "\nCan form consecutive sequence: " 
         << (canFormConsecutive(arr, size) ? "true" : "false") << endl;

    // Deallocate memory
    delete[] arr;
    return 0;
}