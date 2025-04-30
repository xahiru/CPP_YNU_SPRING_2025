#include <iostream>
#include <vector>

int main() {

    std::vector<int> arr = {1, 5, 7, 5, 8, 9, 11, 11, 2, 5, 6};
    

    std::cout << "Original array: ";

    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    // Bubble sort implementation
    int n = arr.size();
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                // Swap elements
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    
    std::cout << "Unique elements of the said array: ";
    
    std::cout << arr[0] << " ";
    

    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] != arr[i-1]) {
            std::cout << arr[i] << " ";
        }
    }
    std::cout << std::endl;
    
    return 0;
}