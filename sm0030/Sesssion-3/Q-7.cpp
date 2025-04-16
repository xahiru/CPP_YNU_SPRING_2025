#include <iostream>

int main() {
    int arr[] = {1, 5, 7, 5, 8, 9, 11, 12};
    int n = sizeof(arr) / sizeof(arr[0]);
    int targetSum = 12;
    int pairCount = 0;

    std::cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Array pairs whose sum equal to " << targetSum << ": ";
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == targetSum) {
                std::cout << arr[i] << "," << arr[j] << " ";
                pairCount++;
            }
        }
    }
    std::cout << std::endl;

    std::cout << "Number of pairs whose sum equal to " << targetSum << ": " << pairCount << std::endl;

    return 0;
}