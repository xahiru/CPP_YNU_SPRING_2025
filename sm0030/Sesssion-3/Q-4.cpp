#include <iostream>

int main() {
    int arr[] = {0, 1, 0, 0, 1, 1, 1, 0, 1, 0};
    int n = sizeof(arr) / sizeof(arr[0]);

    int countZeros = 0;

    // Count the number of zeros in the array
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) {
            countZeros++;
        }
    }

    // Fill the beginning of the array with zeros
    for (int i = 0; i < countZeros; i++) {
        arr[i] = 0;
    }

    // Fill the rest of the array with ones
    for (int i = countZeros; i < n; i++) {
        arr[i] = 1;
    }

    // Print the original array
    std::cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    // Print the array after separation
    std::cout << "Array after divided: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}