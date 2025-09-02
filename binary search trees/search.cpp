#include<iostream>
#include<vector>
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

void inorder(Node* node){
    if(node==nullptr){
        return;
    }
    inorder(node->left);
    cout<<node->data<<"-";
    inorder(node->right);
}

Node* insert(Node* root, int val){
    if(root == nullptr){
        root = new Node(val);
        return root;
    }

    if(val < root->data){ //left subtree
        root->left = insert(root->left, val);
    }
    else{ // right subtree
        root->right = insert(root->right, val);
    }

    return root;
}

Node* buildBST(vector<int> arr, int n){
    Node* root = nullptr;

    for (int i = 0; i < n; i++)
    {
        root = insert(root, arr[i]);
    }
    return root;
}

bool search(Node* root, int val){
    if(root == nullptr){
        return false;
    }

    if(root->data ==  val){
        return true;
    }
    
    if(val < root->data){
        return search(root->left, val);
    }
    else{
        return search(root->right, val);
    }
}

int main()
{
    vector<int> arr = {5,6,7,8,9};
    Node* root = buildBST(arr, 5);
    inorder(root);
    cout<<endl;
    cout<<search(root, 8);

return 0;
}