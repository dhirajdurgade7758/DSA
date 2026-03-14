#include <iostream>
#include <vector>
using namespace std;

// Binary Search Tree Node
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
    if (node == nullptr) return;
    inorder(node->left);
    cout << node->data << " ";
    inorder(node->right);
}

// Insert node in BST
Node* insert(Node* root, int val) {
    if (root == nullptr) {
        return new Node(val);
    }
    if (val < root->data) {
        root->left = insert(root->left, val);
    } else {
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

// Find inorder successor (smallest in right subtree)
Node* inorderSuccessor(Node* root) {
    while (root->left != nullptr) {
        root = root->left;
    }
    return root;
}

// Delete node from BST
Node* delNode(Node* root, int val) {
    if (root == nullptr) return nullptr;

    // Search for the node
    if (val < root->data) {
        root->left = delNode(root->left, val);
    }
    else if (val > root->data) {
        root->right = delNode(root->right, val);
    }
    else {
        // Node found
        // Case 1: 0 children (leaf node)
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            return nullptr;
        }
        // Case 2: 1 child
        else if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        // Case 3: 2 children
        else {
            Node* IS = inorderSuccessor(root->right); // inorder successor
            root->data = IS->data;                    // copy successor value to root
            root->right = delNode(root->right, IS->data); // delete successor node
        }
    }
    return root;
}

// ---------- MAIN FUNCTION ----------
int main() {
    vector<int> arr = {5, 6, 7, 8, 9};
    Node* root = buildBST(arr, arr.size());

    cout << "Before deleting: ";
    inorder(root);
    cout << endl;

    root = delNode(root, 8); // delete node 8

    cout << "After deleting: ";
    inorder(root);
    cout << endl;

    return 0;
}
