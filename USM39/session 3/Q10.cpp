#include <iostream>
using namespace std;

int recursiveSum(int arr[], int size) {
    if (size == 0) {
        return 0;
    }
    return arr[size - 1] + recursiveSum(arr, size - 1);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    cout << "Array elements: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    cout << "Sum of array elements using recursion: " << recursiveSum(arr, size) << endl;
    
    return 0;
}