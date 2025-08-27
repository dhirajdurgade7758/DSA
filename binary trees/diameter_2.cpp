#include<iostream>
#include<vector>
#include<stack>
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
            // Keep going left and push nodes into stack
            s.push(node);
            node = node->left;
        }
        else{
            // If stack becomes empty, traversal is complete
            if(s.empty()) break;
            
            // Process the node
            node = s.top();
            s.pop();
            cout << node->data << "-";
            
            // Move to right subtree
            node = node->right;
        }
    }
}

// Function to calculate height of binary tree
// Height is the number of nodes on the longest path from root to leaf
int height(Node* root){
    if(root == nullptr){
        return 0;
    }
    
    // Recursively calculate height of left and right subtrees
    int left = height(root->left);
    int right = height(root->right);
    
    // Height of current node = max(leftHeight, rightHeight) + 1
    int currht = max(left, right) + 1;
    return currht;
}

// Function to calculate diameter of the tree
// Returns a pair (height, diameter)
// Diameter = longest path between any two nodes in the tree
pair<int, int> diam2(Node* root){
    if(root == nullptr){
        // Base case: height = 0, diameter = 0
        return make_pair(0,0);
    }
    
    // Recursively get information from left and right subtrees
    pair<int, int> leftInfo = diam2(root->left);
    pair<int, int> rightInfo = diam2(root->right);
    
    // Current diameter passing through root
    int currDiam = leftInfo.first + rightInfo.first + 1;
    
    // Final diameter is the maximum of:
    // 1) diameter of left subtree
    // 2) diameter of right subtree
    // 3) diameter passing through root
    int finalDiam = max(currDiam, max(leftInfo.second, rightInfo.second));
    
    // Height of current node
    int finalHeight = max(leftInfo.first, rightInfo.first) + 1;
    
    return make_pair(finalHeight, finalDiam);
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
    
    root->left->left= new Node(4);
    root->left->right = new Node(5);
    
    root->left->right->left = new Node(8);
    
    // Print inorder traversal
    inorder(root);
    cout << endl;
    
    // Print height of tree
    cout << "Height of tree is " << height(root) << endl;
    
    // Print diameter of tree
    pair<int, int> diam = diam2(root);
    cout << "Diameter of tree is " << diam.second;
    
    return 0;
}
