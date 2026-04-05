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

// Preorder traversal (Root → Left → Right)
void preorder(Node* node) {
    if (node == nullptr) {
        return;
    }
    cout << node->data << " ";  // print current node
    preorder(node->left);
    preorder(node->right);
}

// Function to build a Balanced BST from a sorted array
Node* buildBSTFromSortedArray(vector<int> arr, int st, int end) {
    if (st > end) {
        return nullptr;
    }

    // Find middle element (to keep tree balanced)
    int mid = st + (end - st) / 2;

    // Create new node with middle element
    Node* curr = new Node(arr[mid]);

    // Recursively build left and right subtrees
    curr->left = buildBSTFromSortedArray(arr, st, mid - 1);
    curr->right = buildBSTFromSortedArray(arr, mid + 1, end);

    return curr;
}

int main() {
    vector<int> arr = {3, 4, 5, 6, 7, 8, 9};

    // Build Balanced BST from sorted array
    Node* root = buildBSTFromSortedArray(arr, 0, arr.size() - 1);

    // Print Preorder traversal
    cout << "Preorder Traversal of Balanced BST: ";
    preorder(root);
    cout << endl;

    return 0;
}
