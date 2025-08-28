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

// Utility function: Find path from root to a given node
bool rootTONode(Node* root, int n, vector<int> &path){
    if(root == nullptr){
        return false; // Base case: empty tree
    }
    path.push_back(root->data); // Add current node to path
    
    if(root->data == n){
        return true; // Found target node
    }
    
    // Recur in left or right subtree
    bool isleft = rootTONode(root->left, n, path);
    bool isright = rootTONode(root->right, n, path);
    
    if(isleft || isright){
        return true; // Node found in one of the subtrees
    }
    
    // Backtrack: remove current node if not part of path
    path.pop_back();
    return false;
}

// Function to find Lowest Common Ancestor (LCA) of two nodes
int LCA(Node* root, int n1,int n2){
    if(root == nullptr){
        return -1; // Empty tree
    }
    
    vector<int> path1, path2;
    
    // Check if both nodes exist in the tree
    if (!rootTONode(root, n1, path1) || !rootTONode(root, n2, path2)) {
        return -1; // At least one node not found
    }
    
    int lca = -1;
    // Compare paths until they differ
    for(int i=0, j=0; i<path1.size() && j<path2.size(); i++, j++){
        if(path1[i] != path2[i]){
            break; // Paths diverged
        }
        lca = path1[i]; // Last common node
    }
    return lca;
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
    cout<<"Lowest Common Ancestor of "<<a<<" and "<<b<<" is "<<LCA(root, a,b)<<endl;
    
    return 0;
}
