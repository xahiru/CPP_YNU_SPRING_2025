#include <iostream>
#include <climits> // For INT_MAX
using namespace std;

int main() {
    // Original array
    int arr[] = {5, 6, 7, 2, 3, 4, 12};
    int n = sizeof(arr) / sizeof(arr[0]);

    int smallest = INT_MAX;
    int second_smallest = INT_MAX;

    for (int i = 0; i < n; i++) {
        if (arr[i] < smallest) {
            second_smallest = smallest;
            smallest = arr[i];
        } else if (arr[i] < second_smallest && arr[i] != smallest) {
            second_smallest = arr[i];
        }
    }

    // Output
    cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    if (second_smallest == INT_MAX) {
        cout << "There is no second smallest number (all elements might be equal)." << endl;
    } else {
        cout << "Second smallest number: " << second_smallest << endl;
    }

    return 0;
}
