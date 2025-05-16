#include <iostream>
using namespace std;

int arraySum(int arr[], int size) {
    if (size == 0) return 0;
    return arr[0] + arraySum(arr + 1, size - 1);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "Sum of array elements using recursion: " << arraySum(arr, size);
    return 0;
}