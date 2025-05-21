#include <iostream>
using namespace std;

struct Node {
    bool isLeaf;  // Flag to indicate if this is a leaf node
    
    union {
        struct {
            Node* left;
            Node* right;
        } children;
        
        double data;
    };
    
    // Constructor for leaf node
    Node(double value) : isLeaf(true) {
        data = value;
    }
    
    // Constructor for internal node
    Node(Node* l, Node* r) : isLeaf(false) {
        children.left = l;
        children.right = r;
    }
    
    // Destructor
    ~Node() {
        if (!isLeaf) {
            delete children.left;
            delete children.right;
        }
    }
};

// Function to print the tree (in-order traversal)
void printTree(Node* node) {
    if (node == nullptr) return;
    
    if (node->isLeaf) {
        cout << node->data << " ";
    } else {
        printTree(node->children.left);
        printTree(node->children.right);
    }
}

int main() {
    
    Node* leaf1 = new Node(1.0);
    Node* leaf2 = new Node(2.0);
    Node* leaf3 = new Node(3.0);
    
    Node* internal1 = new Node(leaf2, leaf3);
    Node* root = new Node(leaf1, internal1);
    
    cout << "Tree elements (in-order): ";
    printTree(root);
    cout << endl;
    
    // Clean up memory
    delete root;
    
    return 0;
}