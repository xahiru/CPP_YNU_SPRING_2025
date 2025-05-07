#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    int arr[] = {1,5,7,5,8,9,11,11,2,5,6}, n = 11;
    unordered_set<int> s(arr, arr+n);
    
    cout << "Original array: ";
    for(int x : arr) cout << x << " ";
    
    cout << "\nUnique elements of the said array: ";
    for(int x : s) cout << x << " ";
}