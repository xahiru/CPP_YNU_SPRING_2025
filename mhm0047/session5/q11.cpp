#include <iostream>
#include <iomanip>
using namespace std;

void printAlphabetPyramid(int levels) {
    for (int row = 0; row < levels; ++row) {
        cout << setw(2 * (levels - row - 1)) << "";
        
        for (int asc = 0; asc <= row; ++asc) {
            cout << char('A' + asc) << " ";
        }
        
        for (int desc = row - 1; desc >= 0; --desc) {
            cout << char('A' + desc) << " ";
        }
        
        cout << endl;
    }
}

int main() {
    int letterCount;
    cout << "Enter pyramid height (1-25 letters): ";
    cin >> letterCount;
    
    if (letterCount < 1 || letterCount > 25) {
        cout << "Invalid input. Please enter between 1 and 25." << endl;
        return 1;
    }
    
    printAlphabetPyramid(letterCount);
    return 0;
}