#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    // Sample array
    vector<int> arr = {1, 5, 7, 5, 8, 9, 11, 12};
    int targetSum = 12;
    int pairCount = 0;

    cout << "Original array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    // Using a hash map to store the frequency of each number
    unordered_map<int, int> numCount;

    // Count occurrences of each number
    for (int num : arr) {
        numCount[num]++;
    }

    cout << "Array pairs whose sum equal to " << targetSum << ":\n";

    // Find pairs
    for (int num : arr) {
        int complement = targetSum - num;

        // Check if the complement exists in the map
        if (numCount[complement] > 0) {
            // If the number and its complement are the same, we need to ensure there are at least two occurrences
            if (complement == num) {
                if (numCount[num] > 1) {
                    // Print the pair (num, complement)
                    cout << num << "," << complement << endl;
                    pairCount += numCount[num] - 1; // Count pairs
                }
            } else {
                // Print the pair (num, complement)
                cout << num << "," << complement << endl;
                pairCount += numCount[complement]; // Count pairs
            }
        }
        // Decrease the count of the current number to avoid counting it again
        numCount[num]--;
    }

    cout << "Number of pairs whose sum equal to " << targetSum << ": " << pairCount << endl;

    return 0;
}