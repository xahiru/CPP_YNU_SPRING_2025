#include <iostream>
#include <vector>
#include <cctype>
#include <string>

using namespace std;

vector<string> capitalizeFirstLetters(vector<string> words) {
    for (auto& word : words) {
        if (!word.empty()) {
            word[0] = toupper(word[0]);
        }
    }
    return words;
}

int main() {
    vector<string> words;
    string input;
    int n;
    
    cout << "Enter number of strings: ";
    cin >> n;
    cin.ignore(); // Clear input buffer
    
    cout << "Enter " << n << " strings separated by newlines:\n";
    for (int i = 0; i < n; ++i) {
        getline(cin, input);
        words.push_back(input);
    }
    
    cout << "\nOriginal Vector elements: ";
    for (const auto& word : words) {
        cout << word << " ";
    }
    cout << endl;
    
    vector<string> capitalized = capitalizeFirstLetters(words);
    
    cout << "Capitalized Vector elements: ";
    for (const auto& word : capitalized) {
        cout << word << " ";
    }
    cout << endl;
    
    return 0;
}