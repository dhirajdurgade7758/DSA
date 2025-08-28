#include<iostream>
#include<vector>
#include<stack>
#include<map>
#include<queue>
using namespace std;

// Node structure representing each element of the binary tree
struct Node{
    int data;       // Value stored in the node
    Node* left;     // Pointer to left child
    Node* right;    // Pointer to right child
    
    // Constructor to initialize a new node
    Node(int data){
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

// Iterative Inorder Traversal of a binary tree using stack
void inorder(Node* root){
    stack<Node*> s;
    Node* node = root;
    
    while(true){
        if(node != nullptr){
            // Traverse left and push nodes into stack
            s.push(node);
            node = node->left;
        }
        else{
            if(s.empty()) break;  // End when stack is empty
            
            // Process current node
            node = s.top();
            s.pop();
            cout << node->data << "-";
            
            // Move to right subtree
            node = node->right;
        }
    }
}

// Helper function to print all nodes at kth level
void kthLevelHelper(Node* root, int k, int currLevel){
    if(root == nullptr){
        return;
    }
    
    // If we reach the required level, print node data
    if(currLevel == k){
        cout << root->data << "-";
        return;
    }
    
    // Otherwise, go deeper into left and right subtrees
    kthLevelHelper(root->left, k, currLevel + 1);
    kthLevelHelper(root->right, k, currLevel + 1);
}

// Wrapper function to call helper with starting level = 1 (root level)
void kthLevel(Node* root, int k){
    kthLevelHelper(root, k, 1);
}

int main()
{
    // Constructing the following tree:
    //          1
    //         / \
    //        2   3
    //       / \
    //      4   5
    //         /
    //        8
    
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(8);
    
    // Print inorder traversal
    cout << "Inorder Traversal: ";
    inorder(root);
    cout << endl;
    
    // Print all nodes at 3rd level of tree
    cout << "kth level of tree: ";
    kthLevel(root, 3);
    
    return 0;
}
