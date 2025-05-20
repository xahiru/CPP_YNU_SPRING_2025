#include<iostream>
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

    NODE* root = new NODE;
    root->isLeaf = false;
    root->left = leaf;
    root->right = nullptr;

    cout << "Leaf data: " << leaf->data << endl;
    return 0;
}
