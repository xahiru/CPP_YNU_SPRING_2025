#include <iostream>
#include <cstring> // For strlen and swap functions
using namespace std;

// Recursive function to generate all permutations of a string
void permute(char *str, int l, int r) {
    if (l == r) {
        cout << str << endl;
    } else {
        for (int i = l; i <= r; i++) {
            swap(str[l], str[i]);  // Swap characters
            permute(str, l + 1, r);  // Recursively permute the remaining characters
            swap(str[l], str[i]);  // Backtrack to restore the original string
        }
    }
}

int main() {
    char str[] = "abc";
    int n = strlen(str);
    cout << "All permutations of the string:\n";
    permute(str, 0, n - 1);

    return 0;
}
