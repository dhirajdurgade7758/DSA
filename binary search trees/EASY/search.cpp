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

// Inorder Traversal (Left → Root → Right)
void inorder(Node* node) {
    if (node == nullptr) {
        return;
    }
    inorder(node->left);
    cout << node->data << " ";
    inorder(node->right);
}

// Insert value into BST
Node* insert(Node* root, int val) {
    if (root == nullptr) {
        root = new Node(val);
        return root;
    }
    if (val < root->data) { // left subtree
        root->left = insert(root->left, val);
    } else {                // right subtree
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

// Search for a value in BST
bool search(Node* root, int val) {
    if (root == nullptr) {
        return false;
    }
    if (root->data == val) {
        return true;
    }
    if (val < root->data) {
        return search(root->left, val);
    } else {
        return search(root->right, val);
    }
}

int main() {
    vector<int> arr = {5, 6, 7, 8, 9};

    // Build BST
    Node* root = buildBST(arr, arr.size());

    // Print inorder traversal (sorted order)
    cout << "Inorder Traversal of BST: ";
    inorder(root);
    cout << endl;

    // Search in BST
    int key = 8;
    if (search(root, key)) {
        cout << "Value " << key << " found in BST!" << endl;
    } else {
        cout << "Value " << key << " not found in BST!" << endl;
    }

    return 0;
}
