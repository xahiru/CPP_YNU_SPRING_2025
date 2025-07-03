#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

bool canFormConsecutiveSequence(const vector<int>& nums) {
    if (nums.empty()) return false;

    unordered_set<int> numSet;
    int minNum = INT_MAX;
    int maxNum = INT_MIN;

    for (int num : nums) {
        numSet.insert(num);
        if (num < minNum) minNum = num;
        if (num > maxNum) maxNum = num;
    }

    int expectedSize = maxNum - minNum + 1;

    return numSet.size() == expectedSize;
}

int main() {
    vector<int> numbers = {1, 2, 5, 0, 3, 6, 7};

    if (canFormConsecutiveSequence(numbers)) {
        cout << "The numbers can be rearranged to form a consecutive sequence." << endl;
    } else {
        cout << "The numbers cannot be rearranged to form a consecutive sequence." << endl;
    }

    return 0;
}