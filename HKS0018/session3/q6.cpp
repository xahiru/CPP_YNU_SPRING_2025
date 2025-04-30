#include <iostream>

using namespace std;

int main() {
    int arr[] = {1, 2, 3, 5, 5, 7, 8, 8, 9, 9, 2};

    int n = sizeof(arr) / sizeof(arr[0]);


    // Bubble sort to sort the array
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Repeating elements: ";
    for (int i = 1; i < n; i++) {
        if (arr[i] == arr[i - 1]) {
            cout << arr[i] << " ";
        }
    }
    cout << endl;

    return 0;
}
