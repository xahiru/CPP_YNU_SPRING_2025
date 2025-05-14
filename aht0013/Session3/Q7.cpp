#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;

void findPairs(int arr[], int n, int target) {
    unordered_map<int, int> freq;
    vector<pair<int, int>> unique_pairs;
    int count = 0;

    for(int i = 0; i < n; i++) {
        freq[arr[i]]++;
    }

    for(int i = 0; i < n; i++) {
        int complement = target - arr[i];
        if(freq.find(complement) != freq.end()) {
            if(complement >= arr[i]) {
                if(complement == arr[i]) {
                    if(freq[complement] >= 2) {
                        unique_pairs.push_back({arr[i], complement});
                        count += freq[complement] * (freq[complement] - 1) / 2;
                        freq[complement] = 0;
                    }
                } else {
                    unique_pairs.push_back({arr[i], complement});
                    count += 1;
                    freq[complement] = 0;
                }
            }
        }
    }

    cout << "Array pairs whose sum equal to " << target << ": \n";
    for(auto p : unique_pairs) {
        if(p.first == p.second) {
            cout << p.first << "," << p.second << endl;
        } else {
            cout << p.first << "," << p.second << endl;
            cout << p.second << "," << p.first << endl;
        }
    }

    cout << "Number of pairs whose sum equal to " << target << ": " << count << endl;
}

int main() {
    int arr[] = {1, 5, 7, 5, 8, 9, 11, 12};
    int n = sizeof(arr)/sizeof(arr[0]);
    int target = 12;

    cout << "Original array: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    findPairs(arr, n, target);

    return 0;
}