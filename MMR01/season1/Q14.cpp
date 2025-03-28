#include <iostream>
using namespace std;

int main() {
    int rows;

    cout << "Enter number of rows: "; //ask user enter number of rows
    cin >> rows;

    for(int i = rows; i >= 1; --i) {
        //print spaces
        for(int space = 0; space < rows - i; ++space) {
            cout << " ";
        }
        //print stars
        for(int j = 1; j <= 2 * i - 1; ++j) {
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}