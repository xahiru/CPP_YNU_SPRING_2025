#include <iostream> 
#include <unordered_set> 
using namespace std; 

int main() { 
    int arr[] = {1, 5, 7, 5, 8, 9, 11, 11, 2, 5, 6}; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    unordered_set<int> unique; 
    
    for (int i = 0; i < n; i++) { 
        unique.insert(arr[i]); 
    } 
    
    cout << "Unique elements of the said array: "; 
    
    for (auto x : unique) 
     cout << x << " "; 
     cout << endl; return 0; }
