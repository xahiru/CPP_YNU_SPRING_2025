#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

template <typename T>
void genericSort(vector<T>& arr) {
    sort(arr.begin(), arr.end());
    for (const auto& item : arr) {
        cout << item << " ";
    }
    cout << endl;
}

int main() {
    int type, n;
    cin >> type >> n;
    if (type == 1) {
        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        genericSort(arr);
    } else if (type == 2) {
        vector<string> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        genericSort(arr);
    } else if (type == 3) {
        vector<float> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        genericSort(arr);
    }
    return 0;
}
