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

bool validateHelper(Node* root, Node* min, Node* max){
    if(root == nullptr){
        return true;
    }

    if(min != nullptr && root->data < min->data){
        return false;
    }
    if(max != nullptr && root->data > max->data){
        return false;
    }
    return validateHelper(root->left, min, root) && validateHelper(root->right, root, max);
}

bool validateBST(Node* root){
    return validateHelper(root, nullptr, nullptr);
}

int main() {
    vector<int> arr = {8, 5, 3, 6, 1, 4, 10, 11, 14};

    // Build BST
    Node* root = buildBST(arr, arr.size());

    // Print inorder traversal (should be sorted order)
    cout << "Inorder Traversal of BST: ";
    inorder(root);
    cout << endl;

    cout<<"the tree is validated: "<<validateBST(root);
    return 0;
}
