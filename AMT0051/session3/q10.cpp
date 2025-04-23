#include <iostream>

// Recursive function to calculate sum
int recursiveSum(int arr[], int size) {
    if (size == 0) {
        return 0;  // base case
    }
    return arr[size - 1] + recursiveSum(arr, size - 1);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Array elements: ";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }

    int sum = recursiveSum(arr, size);

    std::cout << "\nSum of array elements using recursion: " << sum << std::endl;

    return 0;
}
