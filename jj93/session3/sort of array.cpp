#include <iostream>
using namespace std;

void sortArray(int arr[], int n) {
    int low = 0, mid = 0, high = n - 1;

    while (mid <= high) {
        if (arr[mid] == 0) {

            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1) {

            mid++;
        }
        else {

            swap(arr[mid], arr[high]);
            high--;
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