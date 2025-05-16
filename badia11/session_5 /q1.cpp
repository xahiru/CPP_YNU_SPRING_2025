#include <iostream>
#include <vector>

std::vector<int> findSmallerThanNeighbours(const std::vector<int>& nums) {
    std::vector<int> result;
    if (nums.size() < 3) return result;
    
    for (size_t i = 1; i < nums.size() - 1; ++i) {
        if (nums[i] < nums[i-1] && nums[i] < nums[i+1]) {
            result.push_back(nums[i]);
        }
    }
    
    return result;
}

int main() {
    std::vector<int> nums = {1, 2, 5, 0, 3, 1, 7};
    std::vector<int> result = findSmallerThanNeighbours(nums);
    
    std::cout << "Vector elements that are smaller than its adjacent neighbours:\n";
    for (int num : result) {
        std::cout << num << "\n";
    }
    
    return 0;
}
