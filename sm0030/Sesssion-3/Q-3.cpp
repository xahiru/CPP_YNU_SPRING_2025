#include <iostream>
#include <limits> // For INT_MAX

int main() {
    int arr[] = {5, 6, 7, 2, 3, 4, 12};
    int n = sizeof(arr) / sizeof(arr[0]);

    if (n < 2) {
        std::cout << "Array must have at least two elements." << std::endl;
        return 1;
    }

    int smallest = std::numeric_limits<int>::max();
    int secondSmallest = std::numeric_limits<int>::max();

    for (int i = 0; i < n; i++) {
        if (arr[i] < smallest) {
            secondSmallest = smallest;
            smallest = arr[i];
        } else if (arr[i] < secondSmallest && arr[i] != smallest) {
            secondSmallest = arr[i];
        }
    }

    std::cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    if (secondSmallest == std::numeric_limits<int>::max()) {
        std::cout << "There is no distinct second smallest element." << std::endl;
    } else {
        std::cout << "Second smallest number: " << secondSmallest << std::endl;
    }

    return 0;
}