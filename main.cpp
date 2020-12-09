#include <iostream>
using namespace std;

class BinarySearchTree {
    // members
    int data;
    BinarySearchTree *left, *right;

public:
    // default constructor
    BinarySearchTree();

    // parameterized constructor
    BinarySearchTree(int);

    // insert
    BinarySearchTree* insert(BinarySearchTree*, int);

    // inorder traversal
    void inorder(BinarySearchTree*);
};

// default constructor
BinarySearchTree::BinarySearchTree() : data(0), left(NULL), right(NULL) {
}

// parameterized constructor
BinarySearchTree::BinarySearchTree(int value) {
    data = value;
    left = right = NULL;
}

// insert
BinarySearchTree* BinarySearchTree::insert(BinarySearchTree* root, int value) {
    if (!root) {
        // insert first node
        return new BinarySearchTree(value);
    }

    // insert data
    if (value > root->data) {
        // right nodes
        root->right = insert(root->right, value);
    } else {
        // lest nodes
        root->left = insert(root->left, value);
    }

    // return inserted root node
    return root;
}

// inorder traversal
void BinarySearchTree::inorder(BinarySearchTree* root) {
    if (!root) {
        return;
    }
    inorder(root->left);
    cout << root->data << endl;
    inorder(root->right);
}

int main() {
    BinarySearchTree bst, *root = NULL;

    root = bst.insert(root, 50);
    bst.insert(root, 30);
    bst.insert(root, 20);
    bst.insert(root, 40);
    bst.insert(root, 70);
    bst.insert(root, 60);
    bst.insert(root, 80);

    bst.inorder(root);

    return 0;
}
