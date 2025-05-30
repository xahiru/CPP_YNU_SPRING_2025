#include <iostream>

using namespace std;

struct NODE {
    bool isLeaf;
    union {
        double data;
        struct {
            NODE* left;
            NODE* right;
        } children;
    };

    NODE(double val) {
        isLeaf = true;
        data = val;
    }

    NODE(NODE* l, NODE* r) {
        isLeaf = false;
        children.left = l;
        children.right = r;
    }
};

void printTree(NODE* root) {
    if (root == nullptr)
        return;

    if (root->isLeaf) {
        cout << root->data << " ";
    } else {
        printTree(root->children.left);
        printTree(root->children.right);
    }
}

int main() {
    NODE* leaf1 = new NODE(3.14);
    NODE* leaf2 = new NODE(2.71);
    NODE* leaf3 = new NODE(1.41);

    NODE* internal1 = new NODE(leaf1, leaf2);
    NODE* root = new NODE(internal1, leaf3);

    cout << "Leaf data in tree: ";
    printTree(root);
    cout << endl;

    return 0;

}
