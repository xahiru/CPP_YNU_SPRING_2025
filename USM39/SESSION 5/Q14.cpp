#include <iostream>
#include <vector>

void doubleValues(std::vector<int>& arr) {
    for (auto& val : arr) {
        val *= 2;
    }
}

int main() {
    std::vector<int> arr = {1, 2, 3};
    std::cout << "Array: [";
    for (const auto& val : arr) {
        std::cout << val << " ";
    }
    std::cout << "]" << std::endl;

    doubleValues(arr);
    
    std::cout << "Doubled Array: [";
    for (const auto& val : arr) {
        std::cout << val << " ";
    }
    std::cout << "]" << std::endl;

    return 0;
}
