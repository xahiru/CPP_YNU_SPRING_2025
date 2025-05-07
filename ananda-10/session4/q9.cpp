#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

bool isConsecutive(vector<int>& nums) {
    if (nums.empty()) return false;

    unordered_set<int> numSet(nums.begin(), nums.end());

    if (numSet.size() != nums.size())
        return false;

    int minVal = *min_element(nums.begin(), nums.end());
    int maxVal = *max_element(nums.begin(), nums.end());

    return (maxVal - minVal + 1 == nums.size());
}

int main() {
    vector<int> nums = {1, 2, 5, 0, 3, 6, 7};
    cout << "Check consecutive numbers in the said vector! ";
    cout << (isConsecutive(nums) ? "1" : "0") << endl;

    return 0;
}

