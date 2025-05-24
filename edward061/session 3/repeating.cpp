#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

void findRepeatingElements(const vector<int>& arr) {
    unordered_set<int> seen;  
    cout << "Repeating elements: ";

    for (int num : arr) {
        if (seen.find(num) != seen.end()) {
            cout << num << " ";  
        } else {
            seen.insert(num);  
        }
    }
    cout << endl;
}

int main() {

    vector<int> arr = {1, 2, 3, 5, 5, 7, 8, 8, 9, 9, 2};

    cout << "Original array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    findRepeatingElements(arr);

    return 0;
}