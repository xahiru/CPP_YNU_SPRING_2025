#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

bool canRearrangeConsecutively(const vector<int>& nums) {
    if (nums.empty()) return false;  
    
    unordered_set<int> uniqueNums(nums.begin(), nums.end());

    int n = uniqueNums.size();

    if (n != nums.size()) {
        return false;
    }

    int minVal = *min_element(uniqueNums.begin(), uniqueNums.end());
    int maxVal = *max_element(uniqueNums.begin(), uniqueNums.end());
    
    min is equal to (n - 1)
    return (maxVal - minVal == n - 1);
}

int main() {
    vector<int> nums = {1, 2, 5, 0, 3, 6, 7};

    bool result = canRearrangeConsecutively(nums);

    if (result) {
        cout << "The numbers can be rearranged consecutively!" << endl;
    } else {
        cout << "The numbers cannot be rearranged consecutively!" << endl;
    }
    
    return 0;
}