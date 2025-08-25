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

void preorder(Node* root){
    vector<vector<int>> ans;
    stack<Node*> s;
    s.push(root);
    
    while(!s.empty()){
            int size = s.size();
            for(int i=0; i<size; i++){
                Node* node = s.top();
                s.pop();
                cout<<node->data<<"-";
                if(node->right != nullptr) s.push(node->right);
                if(node->left != nullptr) s.push(node->left);
            }
    }
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    
    root->left->left= new Node(4);
    root->left->right = new Node(5);
    
    root->left->right->left = new Node(8);
    preorder(root);

return 0;
}