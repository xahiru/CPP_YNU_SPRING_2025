#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n, q;
    cout << "Enter array size (n) and data type (q = 1: int, 2: float, 3: string): ";
    cin >> n >> q;

    if (q == 1) {  
        vector<int> arr(n);
        cout << "Enter " << n << " integer elements:\n";
        for (int i = 0; i < n; i++) cin >> arr[i];
        sort(arr.begin(), arr.end());
        for (int i = 0; i < n; i++) cout << arr[i] << " ";
    }
    else if (q == 2) {  
        vector<float> arr(n);
        cout << "Enter " << n << " float elements:\n";
        for (int i = 0; i < n; i++) cin >> arr[i];
        sort(arr.begin(), arr.end());
        for (int i = 0; i < n; i++) cout << arr[i] << " ";
    }
    else if (q == 3) {  
        vector<string> arr(n);
        cout << "Enter " << n << " strings:\n";
        for (int i = 0; i < n; i++) cin >> arr[i];
        sort(arr.begin(), arr.end());
        for (int i = 0; i < n; i++) cout << arr[i] << " ";
    }
    else {
        cout << "Invalid data type selection!" << endl;
    }

    return 0;
}

