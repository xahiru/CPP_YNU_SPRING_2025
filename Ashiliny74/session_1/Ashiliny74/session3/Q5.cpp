#include <iostream>

using namespace std;

void sortArray(int arr[], int n) {
    int low = 0; // Pointer for next position of 0
    int mid = 0; // Pointer for current element
    int high = n - 1; // Pointer for next position of 2

    // Process elements in the array using three pointers
    while (mid <= high) {
        switch (arr[mid]) {
            case 0:
                swap(arr[low], arr[mid]);
                low++;
                mid++;
                break;
            case 1:
                mid++;
                break;
            case 2:
                swap(arr[mid], arr[high]);
                high--;
                break;
        }
    }
}

int main() {
    int arr[] = {0, 1, 2, 2, 1, 1, 0, 0, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    sortArray(arr, n);

    cout << "Array elements after rearranging: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}