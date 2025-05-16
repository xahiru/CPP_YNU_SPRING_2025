#include <iostream>
#include <vector>
#include <string>
#include <cctype>  // For std::toupper
#include <algorithm>

using namespace std;

// Function to capitalize the first letter of each string in the list
vector<string> transformToTitleCase(const vector<string>& items) {
    vector<string> updated = items;

    for (auto& word : updated) {
        if (!word.empty()) {
            word[0] = static_cast<char>(toupper(word[0]));
        }
    }

    return updated;
}

// Function to display the contents of a string vector
void printStringList(const vector<string>& list, const string& label) {
    cout << label << "\n";
    for (const auto& element : list) {
        cout << element << " ";
    }
    cout << "\n\n";
}

int main() {
    vector<string> paintShades = {"red", "green", "black", "white", "pink"};

    printStringList(paintShades, "Initial list of colors:");

    vector<string> formattedShades = transformToTitleCase(paintShades);

    printStringList(formattedShades, "Colors with capitalized initials:");

    return 0;
}
