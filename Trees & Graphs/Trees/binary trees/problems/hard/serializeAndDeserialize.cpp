#include <iostream>
#include <string>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Codec {
public:

    string serialize(TreeNode* root) {
        if (root == nullptr) return "N,";

        return to_string(root->val) + "," +
               serialize(root->left) +
               serialize(root->right);
    }

    TreeNode* deserializeHelper(string& data, int& idx) {

        if (idx >= data.length()) return nullptr;

        if (data[idx] == 'N') {
            idx += 2;
            return nullptr;
        }

        string num = "";
        while (data[idx] != ',') {
            num += data[idx];
            idx++;
        }
        idx++;

        TreeNode* root = new TreeNode(stoi(num));

        root->left = deserializeHelper(data, idx);
        root->right = deserializeHelper(data, idx);

        return root;
    }

    TreeNode* deserialize(string data) {
        int idx = 0;
        return deserializeHelper(data, idx);
    }
};

// inorder traversal for verification
void inorder(TreeNode* root){
    if(root == nullptr) return;

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main(){

    /*
            1
           / \
          2   3
             / \
            4   5
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    Codec obj;

    string data = obj.serialize(root);
    cout << "Serialized: " << data << endl;

    TreeNode* newRoot = obj.deserialize(data);

    cout << "Inorder after deserialization: ";
    inorder(newRoot);

    return 0;
}