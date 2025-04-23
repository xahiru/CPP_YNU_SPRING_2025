#include <iostream>
using namespace std;

void separateZerosAndOnes(int arr[], int size) {
    int count = 0; // Count of 0s

    // Count the number of 0s
    for (int i = 0; i < size; i++) {
        if (arr[i] == 0)
            count++;
    }

    // Fill the array with 0s up to 'count'
    for (int i = 0; i < count; i++)
        arr[i] = 0;

    // Fill the remaining part with 1s
    for (int i = count; i < size; i++)
        arr[i] = 1;
}

int main() {
    int arr[] = {0, 1, 0, 0, 1, 1, 1, 0, 1, 0};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;

    separateZerosAndOnes(arr, size);

    cout << "Array after divided: ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
