#include <iostream>
#include <algorithm> // for sort()

void findThreeLargestSort(int arr[], int size) {
    if (size < 3) {
        std::cout << "Array size is too small!" << std::endl;
        return;
    }

    // Sort the array in ascending order
    std::sort(arr, arr + size);

    // The last three elements are the largest
    std::cout << "Three largest elements are: "
              << arr[size - 1] << ", " << arr[size - 2] << ", " << arr[size - 3] << std::endl;
}

int main() {
    int arr[] = {7, 12, 9, 15, 19, 32, 56, 70};
    int size = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Original array: ";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    findThreeLargestSort(arr, size);

    return 0;
}