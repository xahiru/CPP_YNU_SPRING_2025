#include <iostream>
#include <string>  
using namespace std;

int main() {
    int rows, cols;

    cout << "Enter the number of rows and columns for the float array: ";
    cin >> rows >> cols;

    float **floatArray = new float*[rows];  
    for (int i = 0; i < rows; ++i) {
        floatArray[i] = new float[cols];  
    }


    cout << "Initializing the float array:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            floatArray[i][j] = (i + 1) * (j + 1) * 0.5;  
        }
    }

    
    string **strArray = new string*[rows]; 
    for (int i = 0; i < rows; ++i) {
        strArray[i] = new string[cols];  
    }

    cout << "Initializing the string array:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            strArray[i][j] = "Row " + to_string(i + 1) + " Col " + to_string(j + 1);
        }
    }

    cout << "\nFloat array elements:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << floatArray[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nString array elements:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << strArray[i][j] << " ";
        }
        cout << endl;
    }


    for (int i = 0; i < rows; ++i) {
        delete[] floatArray[i];  
        delete[] strArray[i];  
    }
    delete[] floatArray;  
    delete[] strArray;  

    return 0;
}