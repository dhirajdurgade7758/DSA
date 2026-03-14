#include <iostream>
#include <vector>
using namespace std;

// Node structure for BST
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

// Inorder traversal (Left → Root → Right)
void inorder(Node* node) {
    if (node == nullptr) {
        return;
    }
    inorder(node->left);
    cout << node->data << " ";  // print current node
    inorder(node->right);
}

// Insert a new value into BST
Node* insert(Node* root, int val) {
    if (root == nullptr) {
        root = new Node(val);
        return root;
    }
    if (val < root->data) { // go to left subtree
        root->left = insert(root->left, val);
    } else {                // go to right subtree
        root->right = insert(root->right, val);
    }
    return root;
}

// Build BST from array
Node* buildBST(vector<int> arr, int n) {
    Node* root = nullptr;
    for (int i = 0; i < n; i++) {
        root = insert(root, arr[i]);
    }
    return root;
}

int main() {
    vector<int> arr = {5, 6, 7, 8, 9};

    // Build BST
    Node* root = buildBST(arr, arr.size());

    // Print inorder traversal (should be sorted order)
    cout << "Inorder Traversal of BST: ";
    inorder(root);
    cout << endl;

    return 0;
}
