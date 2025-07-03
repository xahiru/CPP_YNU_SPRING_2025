#include <iostream>
using namespace std;

int** createMatrix(int r, int c) {
    int** m = new int*[r];
    for (int i = 0; i < r; i++) {
        m[i] = new int[c];
    }
    return m;
}

void fillMatrix(int** m, int r, int c) {
    int count = 1;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            m[i][j] = count++;
        }
    }
}

void printMatrix(int** m, int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << m[i][j] << "\t";
        }
        cout << "\n";
    }
}

void freeMatrix(int** m, int r) {
    for (int i = 0; i < r; i++) {
        delete[] m[i];
    }
    delete[] m;
}

int main() {
    int rowCount, colCount;
    
    cout << "Enter matrix dimensions:\n";
    cout << "Number of rows: ";
    cin >> rowCount;
    cout << "Number of columns: ";
    cin >> colCount;
    
    int** myMatrix = createMatrix(rowCount, colCount);
    fillMatrix(myMatrix, rowCount, colCount);
    
    cout << "\nGenerated matrix:\n";
    printMatrix(myMatrix, rowCount, colCount);
    
    freeMatrix(myMatrix, rowCount);
    
    return 0;
}