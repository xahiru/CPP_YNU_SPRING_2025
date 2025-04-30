#include <iostream>
#include <vector>
#include <limits>

using namespace std;

void findThreeLargest(int arr[], int n) {
    // Initialize the three largest elements
    int first = std::numeric_limits<int>::min();
    int second = std::numeric_limits<int>::min();
    int third = std::numeric_limits<int>::min();

    // Traverse the array
    for (int i = 0; i < n; i++) {
        // Update the largest, second largest, and third largest accordingly
        if (arr[i] > first) {
            third = second;
            second = first;
            first = arr[i];
        } else if (arr[i] > second && arr[i] != first) {
            third = second;
            second = arr[i];
        } else if (arr[i] > third && arr[i] != second && arr[i] != first) {
            third = arr[i];
        }
    }

    if (third == std::numeric_limits<int>::min()) {
        cout << "Not enough distinct elements in the array." << endl;
    } else {
        cout << "Three largest elements are: " << first << ", " << second << ", " << third << endl;
    }
}

int main() {
    int arr[] = {7, 12, 9, 15, 19, 32, 56, 70};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    findThreeLargest(arr, n);

    return 0;
}