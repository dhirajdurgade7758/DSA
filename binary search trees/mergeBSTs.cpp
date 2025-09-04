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
    if (node == nullptr) return;
    cout << node->data << " ";
    preorder(node->left);
    preorder(node->right);
}

// Step 1: Store inorder traversal (sorted values of BST) in array
void getInorder(Node* root, vector<int> &arr) {
    if (root == nullptr) return;
    getInorder(root->left, arr);
    arr.push_back(root->data);
    getInorder(root->right, arr);
}

// Step 2: Build Balanced BST from sorted array
Node* buildBSTFromSortedArray(vector<int> arr, int st, int end) {
    if (st > end) return nullptr;

    int mid = st + (end - st) / 2;  // middle element
    Node* curr = new Node(arr[mid]); // make mid as root

    // Recursively build left and right subtrees
    curr->left = buildBSTFromSortedArray(arr, st, mid - 1);
    curr->right = buildBSTFromSortedArray(arr, mid + 1, end);

    return curr;
}

// Step 3: Merge two BSTs into one balanced BST
Node* mergeBSTs(Node* root1, Node* root2) {
    vector<int> nodes1, nodes2, merged;

    // Get inorder (sorted) arrays
    getInorder(root1, nodes1);
    getInorder(root2, nodes2);

    // Merge two sorted arrays
    int i = 0, j = 0;
    while (i < nodes1.size() && j < nodes2.size()) {
        if (nodes1[i] < nodes2[j]) {
            merged.push_back(nodes1[i++]);
        } else {
            merged.push_back(nodes2[j++]);
        }
    }
    while (i < nodes1.size()) merged.push_back(nodes1[i++]);
    while (j < nodes2.size()) merged.push_back(nodes2[j++]);

    // Build Balanced BST from merged array
    return buildBSTFromSortedArray(merged, 0, merged.size() - 1);
}

int main() {
    // First BST
    Node* root1 = new Node(2);
    root1->left = new Node(1);
    root1->right = new Node(4);

    // Second BST
    Node* root2 = new Node(9);
    root2->left = new Node(3);
    root2->right = new Node(12);

    // Merge BSTs
    Node* root = mergeBSTs(root1, root2);

    cout << "Preorder Traversal of Merged Balanced BST: ";
    preorder(root);
    cout << endl;

    return 0;
}
