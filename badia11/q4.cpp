#include <iostream>
#include <vector>

int main() {
    std::vector<int> arr = {0, 1, 0, 0, 1, 1, 1, 0, 1, 0};
    std::vector<int> separated;

    for (int num : arr) {
        if (num == 0) {
            separated.push_back(0);
        }
    }
    for (int num : arr) {
        if (num == 1) {
            separated.push_back(1);
        }
    }

    std::cout << "Array after divided: ";
    for (int num : separated) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    return 0;
}
