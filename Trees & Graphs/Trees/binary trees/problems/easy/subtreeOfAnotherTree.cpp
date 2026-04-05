#include<iostream>
#include<vector>
#include<stack>
using namespace std;

// Node structure for Binary Tree
struct Node{
    int data;       // data of node
    Node* left;     // pointer to left child
    Node* right;    // pointer to right child
    
    // Constructor to initialize node
    Node(int data){
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

// Iterative Inorder Traversal using stack
void inorder(Node* root){
    stack<Node*> s;
    Node* node = root;
    
    while(true){
        if(node != nullptr){
            // Keep pushing left children into stack
            s.push(node);
            node = node->left;
        }
        else{
            if(s.empty()) break;  // Stop if no nodes are left
            
            // Process node
            node = s.top();
            s.pop();
            cout << node->data << "-";
            
            // Move to right subtree
            node = node->right;
        }
    }
}

// Function to check if two trees are identical
bool isIdentical(Node* root1, Node* root2){
    // If both are null → trees are identical
    if(root1 == nullptr && root2 == nullptr){
        return true;
    }
    
    // If only one is null → not identical
    if(root1 == nullptr || root2 == nullptr){
        return false;
    }
    
    // If data does not match → not identical
    if(root1->data != root2->data){
        return false;
    }
    
    // Recursively check left and right subtrees
    return (
        isIdentical(root1->left, root2->left) &&
        isIdentical(root1->right, root2->right)
    );
}

// Function to check if 'subroot' is a subtree of 'root'
bool subtree(Node* root, Node* subroot){
    // Base cases
    if(root == nullptr && subroot == nullptr){
        return true;   // Both empty trees → valid
    }
    else if(root == nullptr || subroot == nullptr){
        return false;  // One empty, other not → invalid
    }
    
    // If current nodes match, check if subtree is identical
    if(root->data == subroot->data){
        if(isIdentical(root, subroot)){
            return true;
        }
    }
    
    // Otherwise, recursively check left and right subtree
    bool leftsubtree = subtree(root->left, subroot);
    
    if(!leftsubtree){
        return subtree(root->right, subroot);
    }
    return true;
}

int main()
{
    // Constructing the main tree:
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
    
    // Print inorder traversal of tree
    inorder(root);
    cout << endl;
    
    // Construct subroot:
    //       2
    //      / \
    //     4   5
    //        /
    //       8
    Node* subroot = new Node(2);
    subroot->left = new Node(4);
    subroot->right = new Node(5);
    subroot->right->left = new Node(8);
    
    // Check if subroot is subtree of root
    cout << subtree(root, subroot);  // Output: 1 (true)
    
    return 0;
}
