#include <iostream>
#include <vector>

std::vector<int> findSmallerThanNeighbors(const std::vector<int>& vec) {
    std::vector<int> result;

    for (size_t i = 1; i < vec.size() - 1; ++i) {
        if (vec[i] < vec[i - 1] && vec[i] < vec[i + 1]) {
            result.push_back(vec[i]);
        }
    }

    return result;
}

int main() {
    std::vector<int> originalVector = {1, 2, 5, 0, 3, 1, 7};
    
    std::cout << "Original Vector elements:\n";
    for (int num : originalVector) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::vector<int> smallerElements = findSmallerThanNeighbors(originalVector);
    
    std::cout << "Vector elements that are smaller than their adjacent neighbours:\n";
    for (int num : smallerElements) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}