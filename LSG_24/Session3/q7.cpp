#include <iostream>
#include <unordered_map>
using namespace std;

void findPairsWithSum(int arr[], int size, int target) {
    unordered_map<int, int> freq;
    int count = 0;
    
    for (int i = 0; i < size; i++) {
        int complement = target - arr[i];
        if (freq.find(complement) != freq.end()) {
            int pairs = freq[complement];
            for (int j = 0; j < pairs; j++) {
                cout << complement << "," << arr[i] << endl;
                count++;
            }
        }
        freq[arr[i]]++;
    }
    
    cout << "Number of pairs whose sum equal to " << target << ": " << count;
}

int main() {
    int arr[] = {1, 5, 7, 5, 8, 9, 11, 12};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 12;
    
    cout << "Array pairs whose sum equal to " << target << ":\n";
    findPairsWithSum(arr, size, target);
    
    return 0;
}