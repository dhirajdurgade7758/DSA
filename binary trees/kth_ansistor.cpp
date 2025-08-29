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

// Function to find k-th ancestor of a given node
int kthAncestor(Node* root,int node, int k){
    if(root == nullptr){
        return -1;   // Node not found in this path
    }
    
    if(root->data == node){
        return 0;    // Found the target node → distance = 0
    }
    
    // Recur for left and right subtrees
    int leftDist = kthAncestor(root->left, node, k);
    int rightDist = kthAncestor(root->right, node, k);
    
    // If node not found in either subtree
    if(leftDist == -1 && rightDist == -1){
        return -1;
    }
    
    // Pick the valid distance (from either left or right subtree)
    int validDist = (leftDist == -1 ? rightDist : leftDist);
    
    // If the current node is the k-th ancestor
    if(validDist + 1 == k){
        cout << "The " << k << "th ancestor of node " << node 
             << " is: " << root->data << endl;
    }
    
    // Return distance of current node from target node
    return validDist + 1;
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
    
    cout << "Inorder Traversal: ";
    inorder(root);
    cout << endl;
    
    // Example: Find 2nd ancestor of node 4
    kthAncestor(root, 4, 2);
    
    return 0;
}
