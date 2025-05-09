#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

bool canRearrangeConsecutive(vector<int>& nums) {
    if (nums.empty()) return false;
    
    unordered_set<int> num_set(nums.begin(), nums.end());
    if (num_set.size() != nums.size()) return false;
    
    int min_num = *min_element(nums.begin(), nums.end());
    int max_num = *max_element(nums.begin(), nums.end());
    
    return (max_num - min_num + 1) == nums.size();
}

int main() {
    vector<int> nums = {1, 2, 5, 0, 3, 6, 7};
    
    cout << "Check consecutive numbers in the vector: ";
    for (int num : nums) cout << num << " ";
    cout << endl;
    
    if (canRearrangeConsecutive(nums)) {
        cout << "True - Can be rearranged as consecutive numbers." << endl;
    } else {
        cout << "False  - Cannot be rearranged as consecutive numbers." << endl;
    }
    
    return 0;
}