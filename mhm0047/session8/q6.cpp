#include <iostream>
using namespace std;

int main() {
    struct Node {
        bool isLeaf;
        union {
            struct {
                Node* left;
                Node* right;
            };
            double data;
        };
    };

    cout << "Union struct for binary tree node declared." << endl;
    return 0;
}
