#include <iostream>

int findSum(int arr[], int size) {
    // Base case: If the array is empty, the sum is 0
    if (size <= 0) {
        return 0;
    } else {
        // Recursive step: Add the last element to the sum of the rest of the array
        return arr[size - 1] + findSum(arr, size - 1);
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Array elements:";
    for (int i = 0; i < n; i++) {
        std::cout << " " << arr[i];
    }
    std::cout << std::endl;

    int sum = findSum(arr, n);

    std::cout << "Sum of array elements using recursion: " << sum << std::endl;

    return 0;
}