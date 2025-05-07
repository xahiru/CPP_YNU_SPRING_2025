#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int arr[] = {1,5,7,5,8,9,11,12}, target = 12, n = 8, count = 0;
    unordered_map<int,int> m;
    
    cout << "Original array: ";
    for(int x : arr) cout << x << " ";
    
    cout << "\nArray pairs whose sum equal to " << target << ": ";
    for(int x : arr) {
        if(m[target-x]-- > 0) {
            cout << target-x << "," << x << " ";
            count++;
        }
        m[x]++;
    }
    cout << "\nNumber of pairs whose sum equal to " << target << ": " << count;
}