#include <iostream>
#include <climits> // For INT_MIN

int findLargest(int arr[], int size) {
    int largest = INT_MIN; // Initialize with smallest possible integer
    for (int i = 0; i < size; i++) {
        if (arr[i] > largest) {
            largest = arr[i];
        }
    }
    return largest;
}

int main() {
    int arr[] = {5, 4, 9, 12, 8};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    int largest = findLargest(arr, size);
    
    std::cout << "The largest element is: " << largest << std::endl;
    
    return 0;
}