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
int LCA2(Node* root, int n1, int n2){
    if(root == nullptr){
        return -1; // Base case: empty tree
    }
    
    // If current node matches one of the keys, return it
    if(root->data == n1 || root->data == n2){
        return root->data;
    }
    
    // Recur for left and right subtrees
    int leftLCA = LCA2(root->left, n1, n2);
    int rightLCA = LCA2(root->right, n1, n2);
    
    // If both sides return valid nodes, current node is LCA
    if(leftLCA != -1 && rightLCA != -1){
        return root->data;
    }
    
    // Otherwise return the non-null side
    return leftLCA == -1 ? rightLCA : leftLCA;
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
    cout<<"Lowest Common Ancestor of "<<a<<" and "<<b<<" is "<<LCA2(root, a,b)<<endl;
    
    return 0;
}


// 🔑 Key Differences between path-based LCA and this recursive LCA:

// Path-based method:

// Finds the path from root to each node, then compares the paths.

// Requires extra space O(N) to store paths.

// Easier to understand, but slower for large trees.

// Recursive method (your LCA2):

// Traverses the tree once and directly finds LCA.

// Runs in O(N) time with O(H) recursion stack (H = height of tree).

// More efficient and widely used.