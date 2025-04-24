#include <iostream>
#include <vector>
#include <set>

int main() {
    std::vector<int> arr = {1, 5, 7, 5, 8, 9, 11, 11, 2, 5, 6};
    std::set<int> unique_elements(arr.begin(), arr.end());

    std::cout << "Original array: ";
    for (const auto& num : arr) {
        std::cout << num << " ";
    }
    std::cout << "\nUnique elements of the said array: ";
    for (const auto& num : unique_elements) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
