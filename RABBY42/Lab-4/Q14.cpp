#include <iostream>
using namespace std;

int main() {
    int arr[] = {10, 11, 7, 8, 2, 9}; // Predefined array
    int target = 19; // Element to search
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate number of elements
    bool found = false;

    for (int i = 0; i < n; ++i) {
        if (arr[i] == target) {
            cout << target << " found at index " << i << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << target << " not found in the arr[]" << endl;
    }

    return 0;
}