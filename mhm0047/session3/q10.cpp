#include <iostream>
using namespace std;

int sumArray(int arr[], int size) {
    if (size == 0)
        return 0;
    return arr[size - 1] + sumArray(arr, size - 1);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Array elements:\n";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    int sum = sumArray(arr, size);
    cout << "\nSum of array elements using recursion: " << sum << endl;

    return 0;
}