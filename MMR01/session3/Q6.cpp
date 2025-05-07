#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    int arr[] = {1, 1, 3, 5, 5, 7, 8, 8, 9, 1, 3};
    unordered_set<int> seen, repeats;
    
    cout << "Original array: ";
    for (int x : arr) {
        cout << x << " ";
        if (!seen.insert(x).second) repeats.insert(x);
    }
    
    cout << "\nRepeating elements: ";
    for (int x : repeats) cout << x << " ";
}