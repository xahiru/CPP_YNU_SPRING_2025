#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canRearrange(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    for (int i = 1; i < nums.size(); ++i) {
        if (nums[i] != nums[i - 1] + 1) {
            return false;
        }
    }
    return true;
}

int main() {
    vector<int> nums = {1, 2, 5, 0, 3, 4};
    if (canRearrange(nums)) {
        cout << "Yes, the array can be rearranged to form a sequence." << endl;
    } else {
        cout << "No, the array cannot be rearranged to form a sequence." << endl;
    }
    return 0;
}