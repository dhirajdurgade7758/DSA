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

// Recursive function to find Lowest Common Ancestor (LCA)
Node* LCA(Node* root, int n1, int n2){
    if(root == nullptr){
        return nullptr;
    }
    
    // If current node matches one of the targets, return it
    if(root->data == n1 || root->data == n2){
        return root;
    }
    
    // Recur in left and right subtrees
    Node* leftLCA = LCA(root->left, n1, n2);
    Node* rightLCA = LCA(root->right, n1, n2);
    
    // If both sides return non-null → current node is LCA
    if(leftLCA != nullptr && rightLCA != nullptr){
        return root;
    }
    
    // Otherwise return the non-null side
    return leftLCA == nullptr ? rightLCA : leftLCA;
}

// Function to calculate distance from a given root to a node n
int dist(Node* root, int n){
    if(root == nullptr) return -1;
    
    if(root->data == n){
        return 0; // Found the node
    }
    
    // Search in left subtree
    int leftDist = dist(root->left, n);
    if(leftDist != -1){
        return leftDist + 1;
    }
    
    // Search in right subtree
    int rightDist = dist(root->right, n);
    if(rightDist != -1){
        return rightDist + 1;
    }
    
    return -1; // Node not found
}

// Function to find minimum distance between two nodes
int minDist(Node* root, int n1, int n2){
    if(root == nullptr) return -1;
    
    // Step 1: Find LCA of n1 and n2
    Node* lca = LCA(root, n1, n2);
    
    // Step 2: Find distance from LCA to n1 and LCA to n2
    int dist1 = dist(lca,n1);
    int dist2 = dist(lca,n2);
    
    // Step 3: Total distance = dist(LCA→n1) + dist(LCA→n2)
    return dist1 + dist2;
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
    
    int a=4;
    int b=8;
    cout<<"The minimum distance between "<<a<<" and "<<b<<" is: "<<minDist(root, a,b)<<endl;
    
    return 0;
}
