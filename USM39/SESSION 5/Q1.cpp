#include <iostream>
#include <vector>

std::vector<int> smallerThanNeighbours(const std::vector<int>& vec) {
    std::vector<int> result;
    for (size_t i = 1; i < vec.size() - 1; ++i) {
        if (vec[i] < vec[i - 1] && vec[i] < vec[i + 1]) {
            result.push_back(vec[i]);
        }
    }
    return result;
}

int main() {
    std::vector<int> vec = {1, 2, 5, 0, 3, 1, 7};
    auto result = smallerThanNeighbours(vec);
    for (int num : result) {
        std::cout << num << " ";
    }
    return 0;
}
