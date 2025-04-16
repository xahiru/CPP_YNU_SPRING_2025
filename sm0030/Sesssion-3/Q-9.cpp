#include <iostream>

int main() {
    int arr[] = {1, 5, 7, 5, 8, 9, 11, 11, 2, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int uniqueArr[n]; // Maximum possible size for unique elements
    int uniqueCount = 0;

    std::cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    // Iterate through the original array
    for (int i = 0; i < n; i++) {
        bool isUnique = true;
        // Check if the current element already exists in the unique array
        for (int j = 0; j < uniqueCount; j++) {
            if (arr[i] == uniqueArr[j]) {
                isUnique = false;
                break;
            }
        }
        // If the element is unique, add it to the unique array
        if (isUnique) {
            uniqueArr[uniqueCount] = arr[i];
            uniqueCount++;
        }
    }

    std::cout << "Unique elements of the said array: ";
    for (int i = 0; i < uniqueCount; i++) {
        std::cout << uniqueArr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}