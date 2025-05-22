#include <iostream>
#include <vector> // Using std::vector for easier array handling

int main() {
    std::vector<int> arr = {1, 2, 3}; // Create an array of integers

    std::cout << "Array: [";
    for (int val : arr) { // Traverse and print the original array using a range-based for loop
        std::cout << val << (val == arr.back() ? "" : ", ");
    }
    std::cout << "]" << std::endl;

    // Double the values using a reference and a range-based for loop
    for (int& val : arr) { // 'val' is a reference to each element in 'arr'
        val *= 2; // Double the value
    }

    std::cout << "Doubled Array: [";
    for (int val : arr) { // Print the doubled array using a range-based for loop
        std::cout << val << (val == arr.back() ? "" : ", ");
    }
    std::cout << "]" << std::endl;

    return 0;
}