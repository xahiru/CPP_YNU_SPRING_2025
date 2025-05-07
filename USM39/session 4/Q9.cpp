#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool checkConsecutive(vector<int> nums) {
    sort(nums.begin(), nums.end());
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] != nums[i - 1] + 1) return false;
    }
    return true;
}

int main() {
    vector<int> nums = {1, 2, 5, 0, 3, 6, 7};
    cout << (checkConsecutive(nums) ? "true" : "false") << endl;  
    return 0;
}
