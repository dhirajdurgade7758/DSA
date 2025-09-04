#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Node structure for Binary Tree
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

// Helper class to store information about each subtree
class Info {
public:
    bool isBST;  // Is subtree a BST?
    int min;     // Minimum value in subtree
    int max;     // Maximum value in subtree
    int sz;      // Size of subtree (# of nodes)

    Info(bool isBST, int min, int max, int sz) {
        this->isBST = isBST;
        this->min = min;
        this->max = max;
        this->sz = sz;
    }
};

int maxsize = 0; // global variable to track largest BST size

// Function to find the largest BST in a binary tree
Info* largestBST(Node* root) {
    // Base case: Empty tree is a BST of size 0
    if (root == nullptr) {
        return new Info(true, INT_MAX, INT_MIN, 0);
    }

    // Recursively get info about left and right subtrees
    Info* leftInfo = largestBST(root->left);
    Info* rightInfo = largestBST(root->right);

    // Calculate current node's min, max and size
    int currMin = min(root->data, min(leftInfo->min, rightInfo->min));
    int currMax = max(root->data, max(leftInfo->max, rightInfo->max));
    int currSize = leftInfo->sz + rightInfo->sz + 1;

    // If current subtree is a BST
    if (leftInfo->isBST && rightInfo->isBST &&
        leftInfo->max < root->data && root->data < rightInfo->min) {
        
        maxsize = max(maxsize, currSize); // update max BST size
        return new Info(true, currMin, currMax, currSize);
    }

    // Otherwise, not a BST
    return new Info(false, currMin, currMax, currSize);
}

int main() {
    // Build a sample binary tree
    Node* root = new Node(50);
    root->left = new Node(30);
    root->left->left = new Node(5);
    root->left->right = new Node(20);
    root->right = new Node(60);
    root->right->left = new Node(45);
    root->right->right = new Node(70);
    root->right->right->left = new Node(65);
    root->right->right->right = new Node(80);

    // Find largest BST size
    largestBST(root);
    cout << "Largest BST size in the binary tree is: " << maxsize << endl;

    return 0;
}
