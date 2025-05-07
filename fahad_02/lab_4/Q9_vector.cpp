#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isConsecutive(vector<int>& num) {
    if (num.empty()) return false;

    sort(num.begin(), num.end());

    for (size_t i = 1; i < num.size(); ++i) {
        if (num[i] == num[i - 1] || num[i] != num[i - 1] + 1)
            return false;
    }

    return true;
}

int main() {
    vector<int> num = {1, 2, 5, 0, 3, 6, 7};

    if (isConsecutive(num))
        cout << "1" << endl;  
    else
        cout << "0" << endl;  

    return 0;
}
