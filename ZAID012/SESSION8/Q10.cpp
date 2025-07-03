#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template <typename T>
void genericSort(vector<T> &arr) {
    sort(arr.begin(), arr.end());
}

int main() {
    int type, n;
    cin >> n >> type;
    if (type == 1) {
        vector<int> arr(n);
        for (int &x : arr) cin >> x;
        genericSort(arr);
        for (int x : arr) cout << x << " ";
    } else if (type == 2) {
        vector<string> arr(n);
        for (string &x : arr) cin >> x;
        genericSort(arr);
        for (string x : arr) cout << x << " ";
    } else if (type == 3) {
        vector<float> arr(n);
        for (float &x : arr) cin >> x;
        genericSort(arr);
        for (float x : arr) cout << x << " ";
    }
    return 0;
}
