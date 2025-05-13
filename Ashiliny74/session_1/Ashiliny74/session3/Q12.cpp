#include <iostream>
#include <string>
#include <set>

using namespace std;

// Recursive function to generate permutations
void permute(string str, int l, int r, set<string>& permutations) {
    // Base case: if the left index is equal to the right index, we have a permutation
    if (l == r) {
        permutations.insert(str); // Use a set to avoid duplicates
    } else {
        for (int i = l; i <= r; i++) {
            swap(str[l], str[i]); // Swap the current index with the left index
            permute(str, l + 1, r, permutations); // Recur for the next index
            swap(str[l], str[i]); // Backtrack to the original string
        }
    }
}

int main() {
    string str;

    // Input from the user
    cout << "Input a string: ";
    cin >> str;

    set<string> permutations; // Set to store unique permutations

    // Generate permutations
    permute(str, 0, str.length() - 1, permutations);

    // Output the results
    cout << "All permutations of the string:\n";
    for (const string& perm : permutations) {
        cout << perm << endl;
    }

    return 0;
}