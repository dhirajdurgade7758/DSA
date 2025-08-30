/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if(root == nullptr){
            return nullptr; // Base case: empty tree
        }

        // Recursively process left & right children first
        root->left = removeLeafNodes(root->left, target);
        root->right = removeLeafNodes(root->right, target);

        // Now check if current node became a leaf with target value
        if(root->left == nullptr && root->right == nullptr && root->val == target){
            return nullptr; // Delete this leaf
        }

        return root; // Otherwise return updated root
    }
};
