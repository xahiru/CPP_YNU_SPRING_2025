#include <iostream>
using namespace std;

struct Node {
    bool isLeaf;
    union {
        double data;
        struct {
            Node* left;
            Node* right;
        };
    };
};

Node* createLeaf(double val) {
    Node* node = new Node;
    node->isLeaf = true;
    node->data = val;
    return node;
}

Node* createInternal(Node* l, Node* r) {
    Node* node = new Node;
    node->isLeaf = false;
    node->left = l;
    node->right = r;
    return node;
}
