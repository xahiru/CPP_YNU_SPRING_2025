#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

bool canBeConsecutive(vector<int>& nums) {
    if (nums.empty()) return false;

    unordered_set<int> seen;
    int minVal = nums[0];
    int maxVal = nums[0];

    for (int num : nums) {
        if (seen.count(num)) {

            return false;
        }
        seen.insert(num);
        minVal = min(minVal, num);
        maxVal = max(maxVal, num);
    }

    return (maxVal - minVal + 1 == nums.size());
}

int main() {
    vector<int> nums = {1, 2, 5, 0, 3, 6, 7};

    cout << "Check consecutive numbers in the given vector!" << endl;
    bool result = canBeConsecutive(nums);
    cout << (result ? "True" : "False") << endl;

    return 0;
}
