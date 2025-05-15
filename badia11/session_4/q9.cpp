#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canRearrangeConsecutive(vector<int>& nums) {
    if (nums.empty()) return false;
    sort(nums.begin(), nums.end());
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] != nums[i-1] + 1) {
            return false;
        }
    }
    return true;
}

int main() {
    vector<int> nums = {1, 2, 5, 0, 3, 6, 7};
    sort(nums.begin(), nums.end());
    bool result = canRearrangeConsecutive(nums);
    cout << (result ? "true" : "false") << endl;
    return 0;
}
