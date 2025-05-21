#include <iostream>
#include <vector>

using namespace std;

// Function to extract elements smaller than their adjacent ones
vector<int> extractValleys(const vector<int>& data) {
    vector<int> valleys;

    if (data.size() < 3) {
        return valleys;
    }

    for (size_t index = 1; index + 1 < data.size(); ++index) {
        if (data[index] < data[index - 1] && data[index] < data[index + 1]) {
            valleys.push_back(data[index]);
        }
    }

    return valleys;
}

// Function to display vector content
void showVector(const vector<int>& vec, const string& message) {
    cout << message << "\n";
    for (const int& val : vec) {
        cout << val << " ";
    }
    cout << "\n\n";
}

int main() {
    vector<int> sampleInput = {1, 2, 5, 0, 3, 1, 7};

    showVector(sampleInput, "Initial data sequence:");

    vector<int> smallerThanNeighbors = extractValleys(sampleInput);

    showVector(smallerThanNeighbors, "Elements lower than both immediate neighbors:");

    return 0;
}
