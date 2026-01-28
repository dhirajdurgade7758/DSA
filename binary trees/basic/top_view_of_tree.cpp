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
            s.push(node);
            node = node->left;
        }
        else{
            if(s.empty()) break;
            
            node = s.top();
            s.pop();
            cout << node->data << "-";
            
            node = node->right;
        }
    }
}

// Function to print Top View of Binary Tree
void topView(Node* root){
    if(root == nullptr) return;
    
    // Queue will store pairs of (node, horizontal distance)
    queue<pair<Node*, int>> q;
    
    // Map will store {horizontal distance : node->data}
    map<int, int> m;
    
    q.push(make_pair(root, 0));
    
    while(!q.empty()){
        pair<Node*, int> curr = q.front();
        q.pop();
        
        Node* currNode = curr.first;
        int currHd = curr.second;
        
        // Insert node data if this horizontal distance is seen first time
        if(m.find(currHd) == m.end()){
            m[currHd] = currNode->data;
        }
         
        // Push left child with hd - 1
        if(currNode->left != nullptr){
            q.push(make_pair(currNode->left, currHd - 1));
        }
        
        // Push right child with hd + 1
        if(currNode->right != nullptr){
            q.push(make_pair(currNode->right, currHd + 1));
        }
    }
    
    // Print top view from leftmost hd to rightmost hd
    for(auto it : m){
        cout << it.second << "-";
    }
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
    
    cout << "Top View: ";
    topView(root);
    
    return 0;
}
