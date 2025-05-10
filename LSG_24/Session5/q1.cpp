#include <iostream>
#include <vector>
using namespace std;

vector<int> findValleys(const vector<int>& nums) {
    vector<int> valleys;
    if (nums.size() < 3) return valleys;
    
    for (size_t i = 1; i < nums.size()-1; i++) {
        if (nums[i] < nums[i-1] && nums[i] < nums[i+1]) {
            valleys.push_back(nums[i]);
        }
    }
    return valleys;
}

int main() {
    vector<int> nums = {1, 2, 5, 0, 3, 1, 7};
    vector<int> result = findValleys(nums);
    
    cout << "Vector elements that are smaller than its adjacent neighbours:\n";
    for (int num : result) {
        cout << num << endl;
    }
    return 0;
}