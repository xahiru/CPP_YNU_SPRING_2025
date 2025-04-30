#include <iostream>
#include <array>

int main() {
    // Step 1: Create an array of integers
    std::array<int, 3> arr = {1, 2, 3};

    // Step 2: Print the original array
    std::cout << "Array: [";
    for (const auto& value : arr) {
        std::cout << value << " ";
    }
    std::cout << "]" << std::endl;

    // Step 3: Double the values using a reference
    for (auto& value : arr) {
        value *= 2; // Double the value
    }

    // Step 4: Print the doubled array
    std::cout << "Doubled Array: [";
    for (const auto& value : arr) {
        std::cout << value << " ";
    }
    std::cout << "]" << std::endl;

    return 0;
}