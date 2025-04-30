#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

void findRepeating(int arr[], int size) {
    unordered_map<int, int> freq;
    vector<int> result;
    unordered_map<int, bool> added;

    for (int i = 0; i < size; i++) {
        freq[arr[i]]++;
    }

    for (int i = 0; i < size; i++) {
        if (freq[arr[i]] >= 2 && !added[arr[i]]) {
            result.push_back(arr[i]);
            added[arr[i]] = true;
        }
    }

    cout << "Repeating elements: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {1, 2, 3, 5, 5, 7, 8, 8, 9, 9, 2};
    int size = sizeof(arr) / sizeof(arr[0]);
    findRepeating(arr, size);
    return 0;
}