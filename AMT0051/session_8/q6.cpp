#include <iostream>
using namespace std;

struct NODE {
    bool isLeaf;
    union {
        struct {
            NODE* left;
            NODE* right;
        };
        double data;
    };
};

int main() {
    NODE* leaf = new NODE;
    leaf->isLeaf = true;
    leaf->data = 3.14;

    NODE* internal = new NODE;
    internal->isLeaf = false;
    internal->left = leaf;
    internal->right = nullptr;

    cout << "Leaf data: " << leaf->data << endl;
    return 0;
}