#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

void findPairsWithSum(const vector<int>& arr, int sum) {
    unordered_map<int, int> freqMap; 
    int pairCount = 0;

    cout << "Array pairs whose sum equal to " << sum << ": " << endl;

    for (int num : arr) {
        int complement = sum - num;  
        
        if (freqMap.find(complement) != freqMap.end()) {
    
            for (int i = 0; i < freqMap[complement]; ++i) {
                cout << complement << "," << num << endl; 
                pairCount++;
            }
        }
        

        freqMap[num]++;
    }

    cout << "Number of pairs whose sum equal to " << sum << ": " << pairCount << endl;
}

int main() {

    vector<int> arr = {1, 5, 7, 5, 8, 9, 11, 12};
    int sum = 12;

    cout << "Original array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    findPairsWithSum(arr, sum);

    return 0;
}