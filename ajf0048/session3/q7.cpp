#include <iostream> 
using namespace std; 

int main() { 
    int arr[] = {1, 5, 7, 5, 8, 9, 11, 12}; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    int target = 12; 
    int count = 0; 
    
    for (int i = 0; i < n; i++) { 
        for (int j = i + 1; j < n; j++) { 
            if (arr[i] + arr[j] == target) { 
                cout << arr[i] << "," << arr[j] << endl; 
                count++; 
            } 
        } 
    } 
    
    cout << "Number of pairs whose sum equals to " << target << ": " << count << endl; 
    
    return 0; 
}
