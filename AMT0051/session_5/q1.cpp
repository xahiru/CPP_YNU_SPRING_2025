#include <iostream>
#include <vector>

std::vector<int> findSmallerThanNeighbors(const std::vector<int>& nums) {
    std::vector<int> result;
    
    for (size_t i = 1; i < nums.size() - 1; ++i) {
        if (nums[i] < nums[i - 1] && nums[i] < nums[i + 1]) {
            result.push_back(nums[i]);
        }
    }

    return result;
}

int main() {
    std::vector<int> nums = {1, 2, 5, 0, 3, 1, 7};

    std::cout << "Original Vector elements: ";
    for (int n : nums) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    std::vector<int> result = findSmallerThanNeighbors(nums);

    std::cout << "Vector elements that are smaller than its adjacent neighbours: ";
    for (int n : result) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    return 0;
}
