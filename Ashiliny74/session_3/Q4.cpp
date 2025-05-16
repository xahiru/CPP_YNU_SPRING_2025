#include <iostream>
#include <vector>

using namespace std;

void separateZerosAndOnes(int arr[], int n) {
    int zeroCount = 0;

    // Count the number of 0s in the array
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) {
            zeroCount++;
        }
    }

    // Fill the array with 0s and then with 1s
    for (int i = 0; i < n; i++) {
        if (i < zeroCount) {
            arr[i] = 0; // Place 0s in the array
        } else {
            arr[i] = 1; // Place 1s in the array
        }
    }
}

int main() {
    int arr[] = {0, 1, 0, 0, 1, 1, 1, 0, 1, 0};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    separateZerosAndOnes(arr, n);

    cout << "Array after divided: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}