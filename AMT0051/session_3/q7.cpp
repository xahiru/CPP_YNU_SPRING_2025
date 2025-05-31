#include <iostream>
#include <unordered_map>
using namespace std;

void findPairsWithSum(int arr[], int size, int targetSum) {
    unordered_map<int, int> freq;
    int count = 0;

    cout << "Original array: ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;

    cout << "Array pairs whose sum equal to " << targetSum << ": ";

    for (int i = 0; i < size; i++) {
        int complement = targetSum - arr[i];

        if (freq[complement] > 0) {
            for (int j = 0; j < freq[complement]; j++) {
                cout << complement << "," << arr[i] << " ";
                count++;
            }
        }

        freq[arr[i]]++;
    }

    cout << "\nNumber of pairs whose sum equal to " << targetSum << ": " << count << endl;
}

int main() {
    int arr[] = {1, 5, 7, 5, 8, 9, 11, 12};
    int size = sizeof(arr) / sizeof(arr[0]);
    int targetSum = 12;

    findPairsWithSum(arr, size, targetSum);

    return 0;
}
