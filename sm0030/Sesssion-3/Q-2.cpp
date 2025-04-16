#include <iostream>

int main() {
    int arr[] = {7, 12, 9, 15, 19, 32, 56, 70};
    int n = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    int first = -1, second = -1, third = -1;

    for (int i = 0; i < n; i++) {
        if (arr[i] > first) {
            third = second;
            second = first;
            first = arr[i];
        } else if (arr[i] > second) {
            third = second;
            second = arr[i];
        } else if (arr[i] > third) {
            third = arr[i];
        }
    }

    std::cout << "Three largest elements are: " << first << ", " << second << ", " << third << std::endl;

    return 0;
}