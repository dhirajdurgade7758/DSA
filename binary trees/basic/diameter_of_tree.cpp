#include<iostream>
#include<vector>
#include<stack>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    
    Node(int data){
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

void inorder(Node* root){
    stack<Node*> s;
    Node* node = root;
    while(true){
        if(node!=nullptr){
            s.push(node);
            node=node->left;
        }
        else{
            if(s.empty()) break;
            node=s.top();
            s.pop();
            cout<<node->data<<"-";
            node=node->right;
        }
    }
}

int height(Node* root){
    if(root==nullptr){
        return 0;
    }
    int left = height(root->left);
    int right = height(root->right);
    
    int currht = max(left, right) + 1;
    return currht;
}

int diam(Node* root){// O(n^2)
    if(root == nullptr){
        return 0;
    }
    
    int currDiam = height(root->left) + height(root->right) + 1;
    int leftDiam = diam(root->left);
    int rightDiam = diam(root->right);
    return max(currDiam, max(leftDiam, rightDiam));
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    
    root->left->left= new Node(4);
    root->left->right = new Node(5);
    
    root->left->right->left = new Node(8);
    inorder(root);
    cout<<endl;
    cout<<"height of tree is "<<height(root)<<endl;
    cout<<"diameter of a tree "<<diam(root);
return 0;
}