#include <iostream>
using namespace std;

void printMultiplicationTable(int n) {
    for (int row = 1; row <= 10; row++) {
        for (int num = 1; num <= n; num++) {
            cout << num << " × " << row << " = " << (num * row) << "\t";
        }
        cout << "\n";
    }
}

int main() {
    int limit;
    cout << "Enter the number up to which you want the multiplication table: ";
    cin >> limit;
    
    cout << "\nMultiplication Table from 1 to " << limit << ":\n";
    printMultiplicationTable(limit);
    
    return 0;
}