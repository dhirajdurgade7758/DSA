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

void kthLevelHelper(Node* root, int k, int currLevel){
    if(root == nullptr){
        return;
    }
    
    if(currLevel == k){
        cout<<root->data<<"-";
        return;
    }
    kthLevelHelper(root->left, k, currLevel+1);
    kthLevelHelper(root->right, k, currLevel+1);
}
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
    
    cout << "Inorder Traversal: ";
    inorder(root);
    cout << endl;
    
    cout<<"kth level of tree: ";
    kthLevel(root, 3);
    
    return 0;
}
