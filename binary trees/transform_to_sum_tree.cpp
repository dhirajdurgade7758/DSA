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
            // Go left as far as possible, pushing nodes on stack
            s.push(node);
            node = node->left;
        }
        else{
            if(s.empty()) break;   // All nodes processed
            
            // Visit the node
            node = s.top();
            s.pop();
            cout << node->data << "-";
            
            // Move to right subtree
            node = node->right;
        }
    }
}

// Transform tree into Sum Tree
int transformToSumTree(Node* root){
    if (root == nullptr) return 0;

    // Recursively convert left & right subtrees
    int leftSum = transformToSumTree(root->left);
    int rightSum = transformToSumTree(root->right);

    int oldValue = root->data;  // Store original value

    // Replace current node with sum of subtree values
    root->data = leftSum + rightSum;

    // Return sum of current subtree including old value (for parent’s use)
    return oldValue + root->data;
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
    
    cout << "Inorder Traversal before transforming tree: ";
    inorder(root);
    cout << endl;
    
    transformToSumTree(root);

    cout << "Inorder Traversal after transforming tree: ";
    inorder(root);
    cout << endl;
    
    return 0;
}
