#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool validateHelper(TreeNode* root, TreeNode* min, TreeNode* max){
        if(root == nullptr){
            return true;
        }

        if(min != nullptr && root->val <= min->val){
            return false;
        }

        if(max != nullptr && root->val >= max->val){
            return false;
        }

        return validateHelper(root->left, min, root) &&
               validateHelper(root->right, root, max);
    }

    bool isValidBST(TreeNode* root) {
        return validateHelper(root, nullptr, nullptr);
    }
};

int main() {

    /*
            5
           / \
          3   7
         / \   \
        2   4   8
    */

    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(7);

    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);

    root->right->right = new TreeNode(8);

    Solution obj;

    if(obj.isValidBST(root)){
        cout << "Valid BST" << endl;
    }else{
        cout << "Not a BST" << endl;
    }

    return 0;
}