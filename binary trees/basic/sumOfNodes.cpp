#include <bits/stdc++.h>
using namespace std;

// Definition of Node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};

// Function to calculate sum of nodes
int sumOfNodes(Node* root) {
    if (root == nullptr)
        return 0;

    return root->data + sumOfNodes(root->left) + sumOfNodes(root->right);
}

int main() {
    // Sample Binary Tree
    //        1
    //      /   \
    //     2     3
    //    / \   /
    //   4   5 6

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);

    cout << "Sum of nodes: " << sumOfNodes(root);

    return 0;
}
