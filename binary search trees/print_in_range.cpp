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

// Print nodes of BST in a given range [start, end]
void printInRange(Node* root, int start, int end) {
    if (root == nullptr) {
        return;
    }

    // Case 1: Node is within range → print left subtree → print current → right subtree
    if (start <= root->data && root->data <= end) {
        printInRange(root->left, start, end);
        cout << root->data << " ";
        printInRange(root->right, start, end);
    }
    // Case 2: Node value is smaller than range → ignore left subtree
    else if (root->data < start) {
        printInRange(root->right, start, end);
    }
    // Case 3: Node value is greater than range → ignore right subtree
    else {
        printInRange(root->left, start, end);
    }
} // best case

int main() {
    vector<int> arr = {8, 5, 3, 6, 1, 4, 10, 11, 14};

    // Build BST
    Node* root = buildBST(arr, arr.size());

    // Print inorder traversal (should be sorted order)
    cout << "Inorder Traversal of BST: ";
    inorder(root);
    cout << endl;

    // Print nodes in range [5, 12]
    cout << "Nodes in range [5, 12]: ";
    printInRange(root, 5, 12);
    cout << endl;

    return 0;
}
