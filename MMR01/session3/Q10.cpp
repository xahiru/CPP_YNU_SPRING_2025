#include <iostream>
using namespace std;

// Recursive function to calculate sum
int arraySum(int arr[], int size) {
    // Base case: when size is 0
    if (size == 0) {
        return 0;
    }
    // Recursive case: current element + sum of remaining elements
    return arr[size - 1] + arraySum(arr, size - 1);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    cout << "Array elements:";
    for (int i = 0; i < size; i++) {
        cout << " " << arr[i];
    }
    
    cout << "\nSum of array elements using recursion: " << arraySum(arr, size);
    
    return 0;
}