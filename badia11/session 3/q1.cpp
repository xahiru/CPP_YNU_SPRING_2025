#include <iostream>
#include <vector>
#include <limits>

int main() {
    std::vector<double> arr = {5, 4, 9, 12.8};
    int largest = std::numeric_limits<int>::min();

    for (double num : arr) {
        if (num > largest) {
            largest = static_cast<int>(num);
        }
    }

    std::cout << "The largest integer is: " << largest << std::endl;
    return 0;
}
