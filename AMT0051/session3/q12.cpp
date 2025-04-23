#include <iostream>
#include <string>
using namespace std;

// Recursive function to generate permutations
void permute(string str, int left, int right) {
    if (left == right) {
        cout << str << endl;
    } else {
        for (int i = left; i <= right; i++) {
            swap(str[left], str[i]);                // Swap current index with the loop index
            permute(str, left + 1, right);          // Recurse for the rest
            swap(str[left], str[i]);                // Backtrack to restore original string
        }
    }
}

int main() {
    string input;
    cout << "Input a string: ";
    cin >> input;

    cout << "All permutations of the string:" << endl;
    permute(input, 0, input.length() - 1);

    return 0;
}
