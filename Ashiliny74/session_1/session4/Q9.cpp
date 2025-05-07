#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

bool canRearrangeToConsecutive(const std::vector<int>& nums) {
    if (nums.empty()) return false; // If the vector is empty, return false

    int minVal = *std::min_element(nums.begin(), nums.end());
    int maxVal = *std::max_element(nums.begin(), nums.end());

    // Calculate the expected number of unique elements
    int expectedCount = maxVal - minVal + 1;

    // Use a set to check for uniqueness
    std::unordered_set<int> uniqueElements(nums.begin(), nums.end());

    // Check if the size of the set matches the expected count
    return uniqueElements.size() == expectedCount;
}

int main() {
    std::vector<int> nums;
    int input;

    std::cout << "Enter numbers (end with -1): ";
    while (std::cin >> input && input != -1) {
        nums.push_back(input);
    }

    if (canRearrangeToConsecutive(nums)) {
        std::cout << "The numbers can be rearranged to form consecutive numbers." << std::endl;
    } else {
        std::cout << "The numbers cannot be rearranged to form consecutive numbers." << std::endl;
    }

    return 0;
}