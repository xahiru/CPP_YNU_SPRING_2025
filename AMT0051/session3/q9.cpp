#include <iostream>
#include <unordered_set>
#include <vector>

int main() {
    // Sample array
    std::vector<int> arr = {1, 5, 7, 5, 8, 9, 11, 11, 2, 5, 6};

    std::unordered_set<int> unique_elements;

    std::cout << "Original array: ";
    for (int num : arr) {
        std::cout << num << " ";
        unique_elements.insert(num);  // insert each number into the set
    }

    std::cout << "\nUnique elements of the said array: ";
    for (int num : unique_elements) {
        std::cout << num << " ";
    }

    std::cout << std::endl;

    return 0;
}
