#include<iostream>
#include<vector>
#include<queue>
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

vector<vector<int>> levelOrder(Node* root){
    vector<vector<int>> ans;
    queue<Node*> q;
    q.push(root);
    
    while(!q.empty()){
            int size = q.size();
            vector<int> level;
            for(int i=0; i<size; i++){
                Node* node = q.front();
                if(node->left != nullptr) q.push(node->left);
                if(node->right != nullptr) q.push(node->right);
                level.push_back(node->data);
            }
            ans.push_back(level);
    }
    return ans;
}

int main()
{
    Node* root = new Node(5);
    root->left = new Node(6);
    root->right = new Node(7);
    
    root->left->left= new Node(8);
    root->left->right = new Node(9);
    
    root->left->right->left = new Node(7);
    levelOrder(root);

return 0;
}