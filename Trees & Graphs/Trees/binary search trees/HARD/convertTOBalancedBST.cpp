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
    cout << node->data << " ";
    preorder(node->left);
    preorder(node->right);
}

// Step 1: Store inorder traversal (sorted values of BST) in array
void getSortedArray(Node* root, vector<int> &arr) {
    if (root == nullptr) {
        return;
    }
    getSortedArray(root->left, arr);
    arr.push_back(root->data);
    getSortedArray(root->right, arr);
}

// Step 2: Build Balanced BST from sorted array
Node* buildBSTFromSortedArray(vector<int> arr, int st, int end) {
    if (st > end) {
        return nullptr;
    }

    int mid = st + (end - st) / 2;  // middle element

    Node* curr = new Node(arr[mid]); // make mid as root

    // Recursively build left and right subtrees
    curr->left = buildBSTFromSortedArray(arr, st, mid - 1);
    curr->right = buildBSTFromSortedArray(arr, mid + 1, end);

    return curr;
}

int main() {
    // Step 0: Create an unbalanced BST (skewed like a linked list)
    Node* root = new Node(6);
    root->left = new Node(5);
    root->left->left = new Node(4);
    root->left->left->left = new Node(3);
    root->right = new Node(7);
    root->right->right = new Node(8);
    root->right->right->right = new Node(9);

    // Step 1: Get sorted array using inorder traversal
    vector<int> arr;
    getSortedArray(root, arr);

    // Step 2: Build Balanced BST from sorted array
    Node* newroot = buildBSTFromSortedArray(arr, 0, arr.size() - 1);

    // Step 3: Print preorder traversal of balanced BST
    cout << "Preorder Traversal of Balanced BST: ";
    preorder(newroot);
    cout << endl;

    return 0;
}
