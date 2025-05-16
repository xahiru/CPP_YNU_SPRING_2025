#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> findTwoRepeatingNumbers(const vector<int>& arr) {
    unordered_map<int, int> freq;
    vector<int> result;

    for (int num : arr) {
        freq[num]++;
        if (freq[num] == 2) {
            result.push_back(num);
            if (result.size() == 2) {
                break;
            }
        }
    }

    return result;
}

int main() {
    vector<int> arr = {4, 2, 4, 5, 2, 3, 1};
    vector<int> result = findTwoRepeatingNumbers(arr);

    cout << "The two repeating elements are: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}