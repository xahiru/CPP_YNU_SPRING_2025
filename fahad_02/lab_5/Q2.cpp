#include <iostream>
#include <vector>

using namespace std;

// Function to generate a square matrix of given size and value
vector<vector<int>> generateMatrix(int size, int fillValue) {
    return vector<vector<int>>(size, vector<int>(size, fillValue));
}

// Function to display a 2D matrix
void displayMatrix(const vector<vector<int>>& mat) {
    cout << "Generated square matrix:\n";
    for (const auto& row : mat) {
        for (const auto& element : row) {
            cout << element << " ";
        }
        cout << "\n";
    }
}

int main() {
    int dimension, filler;

    // Collecting user inputs
    cout << "Enter matrix dimension: ";
    cin >> dimension;

    cout << "Enter a number to fill the matrix: ";
    cin >> filler;

    // Create and display matrix
    vector<vector<int>> resultMatrix = generateMatrix(dimension, filler);
    displayMatrix(resultMatrix);

    return 0;
}
