#include <iostream>
#include <vector>
#include <set>
#include <limits>
using namespace std;

bool isConsecutiveSequence(const vector<int>& numbers) {
    if (numbers.empty()) return false;

    set<int> unique_numbers;
    int smallest = numeric_limits<int>::max();
    int largest = numeric_limits<int>::min();

    for (int num : numbers) {
        unique_numbers.insert(num);
        if (num < smallest) smallest = num;
        if (num > largest) largest = num;
    }

    int expectedSize = largest - smallest + 1;
    return (unique_numbers.size() == numbers.size() && expectedSize == numbers.size());
}

int main() {
    vector<int> data = {1, 2, 5, 0, 3, 6, 7};

    cout << "Checking if the following vector can form consecutive numbers:\n";
    for (int val : data) cout << val << " ";
    cout << endl;

    if (isConsecutiveSequence(data)) {
        cout << "Result: True - Numbers can be rearranged into a consecutive sequence." << endl;
    } else {
        cout << "Result: False - Cannot form a consecutive sequence." << endl;
    }

    return 0;
}
