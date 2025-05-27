#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int T; cin >> T;
    while (T--) {
        int n, q; cin >> n >> q;
        if (q == 1) {
            vector<int> arr(n);
            for (int& x : arr) cin >> x;
            sort(arr.begin(), arr.end());
            for (int x : arr) cout << x << " ";
        } else if (q == 2) {
            vector<string> arr(n);
            for (string& s : arr) cin >> s;
            sort(arr.begin(), arr.end());
            for (string s : arr) cout << s << " ";
        } else {
            vector<float> arr(n);
            for (float& x : arr) cin >> x;
            sort(arr.begin(), arr.end());
            for (float x : arr) cout << x << " ";
        }
        cout << endl;
    }
}