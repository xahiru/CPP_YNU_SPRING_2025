#include <iostream>

int main() {
    int arr[] = {0, 1, 2, 2, 1, 1, 0, 0, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    int count0 = 0;
    int count1 = 0;
    int count2 = 0;

    // Count the occurrences of 0, 1, and 2
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) {
            count0++;
        } else if (arr[i] == 1) {
            count1++;
        } else {
            count2++;
        }
    }

    // Rearrange the array
    int index = 0;

    // Fill with 0s
    for (int i = 0; i < count0; i++) {
        arr[index++] = 0;
    }

    // Fill with 1s
    for (int i = 0; i < count1; i++) {
        arr[index++] = 1;
    }

    // Fill with 2s
    for (int i = 0; i < count2; i++) {
        arr[index++] = 2;
    }

    // Print the original array
    std::cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    // Print the array after rearranging
    std::cout << "Array elements after rearranging: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}