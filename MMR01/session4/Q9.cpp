#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

bool canRearrangeToConsecutive(const vector<int>& nums) {
    if (nums.empty()) return false;
    
    unordered_set<int> numSet(nums.begin(), nums.end());
    if (numSet.size() != nums.size()) return false;
    
    int min_num = *min_element(nums.begin(), nums.end());
    int max_num = *max_element(nums.begin(), nums.end());
    
    // Check for exactly consecutive numbers
    for (int i = min_num; i <= max_num; i++) {
        if (numSet.find(i) == numSet.end()) {
            return false;
        }
    }
    
    return true;
}

int main() {
    vector<int> nums1 = {1, 2, 3, 4, 5}; // true
    vector<int> nums2 = {1, 2, 5, 0, 3, 6, 7}; // false (missing 4)
    
    cout << boolalpha; // to print true/false instead of 1/0
    cout << canRearrangeToConsecutive(nums1) << endl; // true
    cout << canRearrangeToConsecutive(nums2) << endl; // false
    
    return 0;
}