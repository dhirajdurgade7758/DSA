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

int countNodes(Node* root){
    if(root==nullptr){
        return 0;
    }
    int left = countNodes(root->left);
    int right = countNodes(root->right);
    return left + right + 1;
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
    cout<<"cont of nodes is "<<countNodes(root);
    
return 0;
}