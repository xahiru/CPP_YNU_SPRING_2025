2#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> arr = {5, 4, 9, 12}; // @Safial Given array of integers
    int largest = arr[0]; // @Safial Assume the first element is the largest initially

    for (size_t i = 1; i < arr.size(); ++i) {
        if (arr[i] > largest) {
            largest = arr[i]; // @Safial Update largest if a larger element is found
        }
    }

    std::cout << "---------------------------------------" << std::endl;
    std::cout << "The largest integer is: " << largest << std::endl;

    return 0;
}