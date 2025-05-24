#include <iostream>
using namespace std;

struct NODE {
    bool is_leaf;
    union {
        double data;
        struct {
            NODE* left;
            NODE* right;
        } children;
    };
};

// Example usage
int main() {
    // Create a leaf node
    NODE leaf;
    leaf.is_leaf = true;
    leaf.data = 3.14;

    // Create an internal node
    NODE internal;
    internal.is_leaf = false;
    internal.children.left = &leaf;
    internal.children.right = nullptr;

    // Access data
    cout << "Leaf data: " << leaf.data << endl;  // Output: 3.14
    if (!internal.is_leaf) {
        cout << "Internal node's left child data: " 
             << internal.children.left->data << endl;  // Output: 3.14
    }

    return 0;
}